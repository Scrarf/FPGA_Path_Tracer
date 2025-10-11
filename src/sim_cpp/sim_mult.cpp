#include <memory>
#include <queue>
#include <cmath>
#include <cstdio>
#include "functions.h"
#include "Vmult.h"
#include "verilator_skeleton/verilator_if.h"

#include <verilated_vcd_c.h>

//#define ENABLE_DUMP

#define CLOCK_HIGH (dut->clk)

int SIM_STEPS = 10000000;
int PIPELINE_DELAY = 6;

struct expected_result {
    int time;
    double a, b, c;
};

static double val_a, val_b;

u_float a, b;

static Vmult* dut;
static std::queue<expected_result> expected_output;

#ifdef ENABLE_DUMP
VerilatedVcdC* tfp = new VerilatedVcdC;
#endif

void tb_init(VerilatedContext* contextp) {
    dut = new Vmult(contextp, "mult");
    dut->clk = 1;

    #ifdef ENABLE_DUMP
    dut->trace(tfp, 99);
    tfp->open("logs/vcd/mult.vcd");
    #endif
}

void tb_eval(VerilatedContext* contextp, int* error_count, int* itteration_count) {
    dut->clk = !dut->clk;

    if (CLOCK_HIGH) {
        val_a = random_double(-10, 10);
        val_b = random_double(-10, 10);

        dut->a = double_to_packed_array(val_a);
        dut->b = double_to_packed_array(val_b);

        //printf("val_a binary: %.23b, val_b binary: %.23b\n", dut->a, dut->b);

        expected_output.push({(int)contextp->time() + ((PIPELINE_DELAY) * 2), val_a, val_b, val_a * val_b});
    }

    if (CLOCK_HIGH && contextp->time() > ((PIPELINE_DELAY) * 2)) {
        if (expected_output.empty()) {printf("QUEUE_IS_EMPTY!\n"); };


        auto expected = expected_output.front();
        expected_output.pop();
        if (expected.time != contextp->time()) {
            printf("SYNC_ERROR!\n expected:%d, contextp:%ld.\n", expected.time, contextp->time());
            contextp->gotFinish(true);
            return;
        }

        double got = packed_array_to_double(dut->c);

        

        if (fabs(expected.c - got) > 0.1) {
            printf("Mismatch at t=%ld: %.4f + %.4f = %.4f (got %.4f)\n",
                   contextp->time(), expected.a, expected.b, expected.c, got);
            //printf("Raw packed array: %.23b\n", dut->c);
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


