#include <memory>
#include <queue>
#include <cmath>
#include <cstdio>
#include "functions.h"
#include "VFP21_add.h"
#include "verilator_skeleton/verilator_if.h"

#include <verilated_vcd_c.h>

//#define ENABLE_DUMP

#define CLOCK_HIGH (dut->clk)

int SIM_STEPS = 100000;
int PIPELINE_DELAY = 11;

struct expected_result {
    int time;
    double a, b, ans;
};

static int sign_a, exp_a, frac_a;
static int sign_b, exp_b, frac_b;
static double val_a, val_b;

static VFP21_add* dut;
static std::queue<expected_result> expected_output;

#ifdef ENABLE_DUMP
VerilatedVcdC* tfp = new VerilatedVcdC;
#endif

void tb_init(VerilatedContext* contextp) {
    dut = new VFP21_add(contextp, "FP21_add");
    dut->clk = 1;

    #ifdef ENABLE_DUMP
    dut->trace(tfp, 99);
    tfp->open("logs/vcd/FP21_add.vcd");
    #endif
}

void tb_eval(VerilatedContext* contextp, int* error_count, int* itteration_count) {
    dut->clk = !dut->clk;

    if (CLOCK_HIGH) {
        val_a = random_double(-10, 10);
        to_int(val_a, &sign_a, &exp_a, &frac_a);

        val_b = random_double(-10, 10);
        to_int(val_b, &sign_b, &exp_b, &frac_b);

        dut->sign_a = sign_a;
        dut->sign_b = sign_b;
        dut->exp_a = exp_a;
        dut->exp_b = exp_b;
        dut->frac_a = frac_a;
        dut->frac_b = frac_b;

        expected_output.push({(int)contextp->time() + ((PIPELINE_DELAY) * 2), val_a, val_b, val_a + val_b});
    }

    if (CLOCK_HIGH && contextp->time() > ((PIPELINE_DELAY) * 2)) {
        if (expected_output.empty()) {printf("QUEUE_IS_EMPTY!\n"); };

        auto expected = expected_output.front();
        expected_output.pop();

        if (expected.time != contextp->time()) {
            printf("SYNC_ERROR!\n expected:%d, contextp:%d.\n", expected.time, contextp->time());
            contextp->gotFinish(true);
            return;
        }

        double got = to_double(dut->sign_c_out, dut->exp_c_out, dut->frac_c_out);

        if (fabs(expected.ans - got) > 0.1) {
            printf("Mismatch at t=%d: %.4f + %.4f = %.4f (got %.4f)\n",
                   contextp->time(), expected.a, expected.b, expected.ans, got);
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


