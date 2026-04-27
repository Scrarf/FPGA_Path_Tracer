#include <cmath>
#include <cstdio>
#include "functions.h"
#include "Vless_than.h"
#include "verilator_skeleton/verilator_if.h"

#define CLOCK_HIGH (dut->clk)

int SIM_STEPS = 1000000000;
int PIPELINE_DELAY = 1;

static int sign_a, exp_a, frac_a;
static int sign_b, exp_b, frac_b;
static double val_a, val_b;

static Vless_than* dut;

void tb_init(VerilatedContext* contextp) {
    dut = new Vless_than(contextp, "less_than");
}

void tb_eval(VerilatedContext* contextp, int* error_count, int* itteration_count) {

    val_a = random_double(-1000, 1000);
    val_b = random_double(-1000, 1000);

	dut->a = double_to_packed_array(val_a);
	dut->b = double_to_packed_array(val_b);

    dut->eval();

    if (dut->result == (val_a > val_b)) {
		printf("missmatch: t=%d a=%f b=%f\n",contextp->time(), val_a, val_b);
    }
}

void tb_end() {
    dut->final();
    delete dut;
    return;
}


