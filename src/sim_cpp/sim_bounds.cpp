#include <memory>
#include <queue>
#include <cmath>
#include <cstdio>
#include "functions.h"
#include "Vbounds.h"
#include "verilator_skeleton/verilator_if.h"

#include <verilated_vcd_c.h>

#include <stdio.h>
#include <stdlib.h>

//#define ENABLE_DUMP

int PIPELINE_DELAY = 2;
int SIM_STEPS = 10;

struct expected_result {
    int time;
    double a, b, c;
};

static double val_a, val_b;

Vbounds* dut;

#ifdef ENABLE_DUMP
VerilatedVcdC* tfp = new VerilatedVcdC;
#endif

#pragma pack(push, 1)
typedef struct {
    float normal[3];
    float v[3][3];
    uint16_t attr;
} stl_triangle;
#pragma pack(pop)

stl_triangle* triangles;
uint32_t triangle_count;

void tb_init(VerilatedContext* contextp) {
    dut = new Vbounds(contextp, "bounds");
    
    dut->rst = 1;
    dut->clk = 0; dut->eval();
    dut->clk = 1; dut->eval();  // rst=1 registered here
    dut->clk = 0; dut->eval();
    dut->rst = 0;
    dut->clk = 1; dut->eval();  // rst=0 registered here

    #ifdef ENABLE_DUMP
    dut->trace(tfp, 99);
    tfp->open("logs/vcd/bounds.vcd");
    #endif

	FILE* f = fopen("models/stanford_dragon.stl", "rb");
	if (!f) {
	    printf("ERROR: could not open STL file, check path\n");
	    exit(1);
	}
	fseek(f, 80, SEEK_SET);

    
    fread(&triangle_count, 4, 1, f);

    triangles = (stl_triangle*)malloc(triangle_count * sizeof(stl_triangle));
    fread(triangles, sizeof(stl_triangle), triangle_count, f);

    printf("triangle_count: %d\n", triangle_count);

    SIM_STEPS = triangle_count + 3;
    
    fclose(f);

	/*for (int i = 0; i < triangle_count; i++) {
	    //printf("normal: (%f, %f, %f)\n",
	    //    triangles[i].normal[0], triangles[i].normal[1], triangles[i].normal[2]);
	    printf("  v1: (%f, %f, %f)\n",
	        triangles[i].v[0][0], triangles[i].v[0][1], triangles[i].v[0][2]);
	    printf("  v2: (%f, %f, %f)\n",
	        triangles[i].v[1][0], triangles[i].v[1][1], triangles[i].v[1][2]);
	    printf("  v3: (%f, %f, %f)\n\n",
	        triangles[i].v[2][0], triangles[i].v[2][1], triangles[i].v[2][2]);
	}*/

}
int steps = 0;

double min_out_x, min_out_y, min_out_z;
double max_out_x, max_out_y, max_out_z;

double test_min_x = 1e9,  test_min_y = 1e9,  test_min_z = 1e9;
double test_max_x = -1e9, test_max_y = -1e9, test_max_z = -1e9;

uint64_t px, py, pz;
	
void tb_eval(VerilatedContext* contextp, int* error_count, int* itteration_count) {

	if (steps < triangle_count*3) {
		dut->valid = 1;
		double x = triangles[steps/3].v[steps%3][0];
		double y = triangles[steps/3].v[steps%3][1];
		double z = triangles[steps/3].v[steps%3][2];

		uint64_t px = double_to_packed_array(x);
		x = packed_array_to_double(px);

		uint64_t py = double_to_packed_array(y);
		y = packed_array_to_double(py);

		uint64_t pz = double_to_packed_array(z);
		z = packed_array_to_double(pz);

		double3_to_packed_float3((uint32_t*)&(dut->flt), x, y, z);
		
		if (x < test_min_x) {
			test_min_x = x;
		}
		if (y < test_min_y) {
			test_min_y = y;
		}
		if (z < test_min_z) {
			test_min_z = z;
		}
		
		if (x > test_max_x) {
			test_max_x = x;
		}
		if (y > test_max_y) {
			test_max_y = y;
		}
		if (z > test_max_z) {
			test_max_z = z;
		}
	}
	else {
		dut->valid = 0;
	}
	
	
	dut->clk = 0;
	dut->eval();
	dut->clk = 1;
	dut->eval();

	if (steps >= triangle_count*3+PIPELINE_DELAY) {
			contextp->gotFinish(true);
	}

	steps++;

    #ifdef ENABLE_DUMP
        tfp->dump(contextp->time());
    #endif
	
    dut->eval();
}

void tb_end() {

	packed_float3_to_double3(&min_out_x, &min_out_y, &min_out_z, (uint32_t*)&(dut->min));
	packed_float3_to_double3(&max_out_x, &max_out_y, &max_out_z, (uint32_t*)&(dut->max));
	
	printf("got:\n");
	printf("min: %f, %f, %f.\n", min_out_x, min_out_y, min_out_z);
	printf("max: %f, %f, %f.\n\n", max_out_x, max_out_y, max_out_z);
	
	printf("correct:\n");
	printf("min: %f, %f, %f.\n", test_min_x, test_min_y, test_min_z);
	printf("max: %f, %f, %f.\n\n", test_max_x, test_max_y, test_max_z);
		
	free(triangles);
    #ifdef ENABLE_DUMP
    tfp->close();
    printf("Dump successful\n");
    #endif

    dut->final();
    delete dut;
    return;
}


