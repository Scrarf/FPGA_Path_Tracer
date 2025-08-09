#include <memory>
#include <verilated.h>
#include "../obj_dir/VFP21_add.h"
#include <verilated_vcd_c.h>
#include <math.h>
#include <stdio.h>
#include <random>
#include <queue>
#include "functions.h"

#include "VFP21_add.h"

//For long error rate testing.
//#define SIM_STEPS 1000000000

//For fast confirmation
#define SIM_STEPS 100000

#define PIPELINE_DELAY 11




double sc_time_stamp() { return 0; }

struct queue_dl {
	int time;
	double a;
	double b;
	double ans;
};

std::queue<queue_dl> expected_output;

int error_count = 0;

int sign_a, exp_a, frac_a;
int sign_b, exp_b, frac_b;

double val_a = 0;
double val_b = 0;

int main(int argc, char** argv) {

		printf("LETS START!!! WEEEE!!!!!\n");

		const std::unique_ptr<VerilatedContext> contextp{new VerilatedContext};

		contextp->debug(0);
		contextp->randReset(2);
		contextp->traceEverOn(true);
		contextp->commandArgs(argc, argv);

		const std::unique_ptr<VFP21_add> FP21_add{new VFP21_add{contextp.get(), "FP21_add"}};

		VerilatedVcdC* tfp = new VerilatedVcdC;
		FP21_add->trace(tfp, 99);
		tfp->open("logs/FP21_add.vcd");

		FP21_add->clk = 0;
    	
		
		while (!contextp->gotFinish()) {
				contextp->timeInc(1);
	
			FP21_add->clk = !FP21_add->clk;

			
	
			if (FP21_add->clk) {

				val_a = random_double(0, 10.0);
				to_int(val_a, &sign_a, &exp_a, &frac_a);
					
				val_b = random_double(0, 10.0);
				to_int(val_b, &sign_b, &exp_b, &frac_b);

				FP21_add->sign_a = sign_a;
				FP21_add->sign_b = sign_b;
				FP21_add->exp_a = exp_a;
				FP21_add->exp_b = exp_b;
				FP21_add->frac_a = frac_a;
				FP21_add->frac_b = frac_b;

				expected_output.push({contextp->time() + ((PIPELINE_DELAY-1)*2), val_a, val_b, val_a + val_b});
			}

			FP21_add->eval();
 		  	
 		  	if (FP21_add->clk && ((contextp->time() > ((PIPELINE_DELAY-1)*2)  ))) {

 		  		queue_dl expected_result = {0, 0, 0, 0};

 		  		if (!expected_output.empty()) {
 		  			expected_result = expected_output.front();
 		  			expected_output.pop();
 		  			//printf("queue_size=%d\n", expected_output.size());
 		  		} else {
 		  			printf("QUEUE_IS_EMPTY\n");
 		  			contextp->gotFinish(true);
 		  		}
 		  		if (expected_result.time != contextp->time()) {
 		  			printf("SYNCHRONIZATION_ERROR!\n");
 		  			contextp->gotFinish(true);
 		  		}

 		  		double ans_to_double = to_double(FP21_add->sign_c_out, FP21_add->exp_c_out, FP21_add->frac_c_out);

 		  		if (abs(expected_result.ans - ans_to_double) > 0.1) {
 		  		printf("t=%d et=%d a=%.6lf b=%.6lf expt=%.6lf rly=%.6lf \n",
 		  			contextp->time(),
 		  			expected_result.time,
 		  			expected_result.a,
 		  			expected_result.b,
 		  			expected_result.ans,
 		  			ans_to_double);

 		  			error_count++;
 		  			printf("sign_c=%b exp_c=%b frac_c=%b\n",FP21_add->sign_c_out, FP21_add->exp_c_out, FP21_add->frac_c_out);
 		  		}

 		  		

 		  	}
 		  	tfp->dump(contextp->time());
 		  	

 		  	FP21_add->eval();


 		  	if ((contextp->time()) > SIM_STEPS) {
 		  		contextp->gotFinish(true);
 		  	}
 		      
		}
		tfp->close();
		printf("error_rate: %f%\n", error_count / ((double)(SIM_STEPS - PIPELINE_DELAY - 1) / 2) * 100.0);
		
		FP21_add->final();

		//Coverage analysis (--coverage)
		#if VM_COVERAGE
 		  Verilated::mkdir("logs");
 		  contextp->coveragep()->write("logs/coverage.dat");
		#endif

		contextp->statsPrintSummary();

		return 0;
}