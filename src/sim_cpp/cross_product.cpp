#include <memory>
#include <queue>
#include <cmath>
#include <cstdio>
#include "functions.h"
#include "Vcross_product.h"
#include "verilator_skeleton/verilator_if.h"

#define CLOCK_HIGH (dut->clk)

int SIM_STEPS = 100000;
int PIPELINE_DELAY = 17;


struct expected_result {
    int time;
    double in[12];
    double ans[3];
};


void cross_product_formula (double ans[3], double in[12]) {
    ans[0] = (in[0] * in[1]) - (in[2] * in[3]);
    ans[1] = (in[4] * in[5]) - (in[6] * in[7]);
    ans[2] = (in[8] * in[9]) - (in[10] * in[11]);

}



static int sign_in[12];
static int exp_in[12];
static int frac_in[12];

static Vcross_product* dut;
static std::queue<expected_result> expected_output;


void tb_init(VerilatedContext* contextp) {
    dut = new Vcross_product(contextp, "cross_product");
    dut->clk = 1;
}

void tb_eval(VerilatedContext* contextp, int* error_count, int* itteration_count) {
    dut->clk = !dut->clk;
    
    if (CLOCK_HIGH) {
        double tmp_double[12];
        int tmp_sign_in, tmp_exp_in, tmp_frac_in;
        for (int i = 0; i < 12; i++) {
            tmp_double[i] = random_double(-10, 10);
            to_int(tmp_double[i], &tmp_sign_in, &tmp_exp_in, &tmp_frac_in);
            dut->sign_in[i] = tmp_sign_in;
            dut->exp_in[i] = tmp_exp_in;
            dut->frac_in[i] = tmp_frac_in;
        }

        double formula_ans[3];

        cross_product_formula(formula_ans, tmp_double);

        expected_result tmp_str;

        tmp_str.time = (int)contextp->time() + (PIPELINE_DELAY * 2);
        for (int i = 0; i < 12; i++) tmp_str.in[i] = tmp_double[i];
        for (int i = 0; i < 3; i++) tmp_str.ans[i] = formula_ans[i];

        expected_output.push(tmp_str);
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
        double got[3];
        for (int i = 0; i < 3; i++) got[i] = to_double(dut->sign_out[i], dut->exp_out[i], dut->frac_out[i]);
        
        bool mistake_happened = 0;
        for (int i = 0; i < 3; i++) {
            if ((fabs(expected.ans[i] - got[i]) > 0.0001)) {
                mistake_happened = 1;
                break;
            }
        }
        
        if (mistake_happened) {
            //printf("Mismatch at t=%d: %.4f * %.4f = %.4f (got %.4f)\n",
            //       contextp->time(), expected.a, expected.b, expected.ans, got);
            printf("error_found\n");
            (*error_count)++;
        }

        (*itteration_count)++;
    
    }
    dut->eval();
}

void tb_end() {
    dut->final();
    delete dut;
    return;
}


