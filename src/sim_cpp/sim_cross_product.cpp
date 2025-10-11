#include <memory>
#include <queue>
#include <cmath>
#include <cstdio>
#include "functions.h"
#include "Vcross_product.h"
#include "verilator_skeleton/verilator_if.h"

#include <verilated_vcd_c.h>

//#define ENABLE_DUMP

#define CLOCK_HIGH (dut->clk)

int SIM_STEPS = 10000;
int PIPELINE_DELAY = 17;

struct expected_result {
    int time;
    double arr_in[6];
    double arr_out[3];
};


static double rand_double[6];

static Vcross_product* dut;
static std::queue<expected_result> expected_output;

#ifdef ENABLE_DUMP
VerilatedVcdC* tfp = new VerilatedVcdC;
#endif

void cross_product(double arr_out[], double arr_in[]) {

	arr_out[0] = arr_in[1] * arr_in[5] - arr_in[2] * arr_in[4];
	arr_out[1] = arr_in[2] * arr_in[3] - arr_in[0] * arr_in[5];
	arr_out[2] = arr_in[0] * arr_in[4] - arr_in[1] * arr_in[3];
	
	return;
}


void tb_init(VerilatedContext* contextp) {
    dut = new Vcross_product(contextp, "cross_product");
    dut->clk = 1;

    #ifdef ENABLE_DUMP
    dut->trace(tfp, 99);
    tfp->open("logs/vcd/cross_product.vcd");
    #endif
}

void tb_eval(VerilatedContext* contextp, int* error_count, int* itteration_count) {
    dut->clk = !dut->clk;

    if (CLOCK_HIGH) {
    	for (int i = 0; i < 6; i++) {
        	rand_double[i] = random_double(-10, 10);
    	}

		uint32_t p_float3_a[3];
		uint32_t p_float3_b[3];
		
		double3_to_packed_float3(p_float3_a, rand_double[0], rand_double[1], rand_double[2]);
		double3_to_packed_float3(p_float3_b, rand_double[3], rand_double[4], rand_double[5]);

        for (int i = 0; i < 6; i++) {
        	dut->a[i] = p_float3_a[i];
        	dut->b[i] = p_float3_b[i];
        }

		double ans_arr[3];
		cross_product(ans_arr, rand_double);

        expected_output.push({(int)contextp->time() + (PIPELINE_DELAY * 2),
        {rand_double[0], rand_double[1], rand_double[2], rand_double[3], rand_double[4], rand_double[5]},
        {ans_arr[0], ans_arr[1], ans_arr[2]} });
    }

    if (CLOCK_HIGH && contextp->time() > (PIPELINE_DELAY * 2)) {
        if (expected_output.empty()) {printf("QUEUE_IS_EMPTY!\n"); };

        auto expected = expected_output.front();
        expected_output.pop();

        if (expected.time != contextp->time()) {
            printf("SYNC_ERROR!\n expected:%d, contextp:%d.\n", expected.time, contextp->time());
            contextp->gotFinish(true);
            return;
        }

		double got_x, got_y, got_z;
		packed_float3_to_double(&got_x, &got_y, &got_z, dut->c);
        
        if ((fabs(expected.arr_out[0] - got_x) > 0.1) || (fabs(expected.arr_out[1] - got_y) > 0.1) || (fabs(expected.arr_out[2] - got_z) > 0.1)) {
            //printf("Mismatch at t=%d: %.4f + %.4f = %.4f (got %.4f)\n",
            //       contextp->time(), expected.a, expected.b, expected.c, got);
            //printf("Raw packed array: %.23b\n", dut->c);
            printf("error occoured!\n");
            (*error_count)++;
        }
        (*itteration_count)++;

   
    }

    #ifdef ENABLE_DUMP
        tfp->dump(contextp->time());
    #endif

    dut->eval();
}

void tb_end() {
    #ifdef ENABLE_DUMP
    tfp->close();
    printf("Dump successful\n");
    #endif

    dut->final();
    delete dut;
    return;
}


