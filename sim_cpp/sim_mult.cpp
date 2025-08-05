#include <memory>
#include <verilated.h>
#include "../obj_dir/VFP21_mult.h"
#include <verilated_vcd_c.h>
#include <math.h>
#include <stdio.h>
#include <random>
#include <queue>
#include "functions.h"

//For long error rate testing.
//#define SIM_STEPS 1000000000
//For fast confirmation
#define SIM_STEPS 1000

#define PIPELINE_DELAY 5

double sc_time_stamp() { return 0; }

struct queue_dl {
	int time;
	double a;
	double b;
	double ans;
};

std::queue<queue_dl> expected_output;

int main(int argc, char** argv) {

		printf("LETS START!!! WEEEE!!!!!\n");

		const std::unique_ptr<VerilatedContext> contextp{new VerilatedContext};

		contextp->debug(0);
		contextp->randReset(2);
		contextp->traceEverOn(true);
		contextp->commandArgs(argc, argv);

		const std::unique_ptr<VFP21_mult> FP21_mult{new VFP21_mult{contextp.get(), "FP21_mult"}};

		FP21_mult->clk = 0;
    	
		int error_count = 0;

		unsigned int sign_a, exp_a, frac_a;
		unsigned int sign_b, exp_b, frac_b;

		double val_a = 0;
		double val_b = 0;

		while (!contextp->gotFinish()) {
				contextp->timeInc(1);
	
			FP21_mult->clk = !FP21_mult->clk;

			
	
			if (FP21_mult->clk) {

				val_a = random_double(-10.0, 10.0);
				to_int(val_a, &sign_a, &exp_a, &frac_a);
					
				val_b = random_double(-10.0, 10.0);
				to_int(val_b, &sign_b, &exp_b, &frac_b);

				FP21_mult->sign_a = sign_a;
				FP21_mult->sign_b = sign_b;
				FP21_mult->exp_a = exp_a;
				FP21_mult->exp_b = exp_b;
				FP21_mult->frac_a = frac_a;
				FP21_mult->frac_b = frac_b;

				expected_output.push({contextp->time() + (PIPELINE_DELAY*2), val_a, val_b, val_a * val_b});
			}
			
			
 		  	
 		  	if (FP21_mult->clk && contextp->time() > (PIPELINE_DELAY*2)) {

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

 		  		double ans_to_double = to_double(FP21_mult->sign_c_out, FP21_mult->exp_c_out, FP21_mult->frac_c_out);

 		  		if ((expected_result.ans - ans_to_double) > 1) {
 		  		printf("t=%d et=%d a=%f b=%f expt=%f rly=%f \n",
 		  			contextp->time(),
 		  			expected_result.time,
 		  			expected_result.a,
 		  			expected_result.b,
 		  			expected_result.ans,
 		  			ans_to_double);

 		  			error_count++;
 		  		}

 		  	}

 		  	FP21_mult->eval();

 		  	


 		  	if ((contextp->time()) > SIM_STEPS) {
 		  		contextp->gotFinish(true);
 		  	}
 		      
		}
		printf("error_rate: %f%\n", (double)( (double)error_count / (double)SIM_STEPS * 100.0 * 2));
		
		FP21_mult->final();

		//Coverage analysis (--coverage)
		#if VM_COVERAGE
 		  Verilated::mkdir("logs");
 		  contextp->coveragep()->write("logs/coverage.dat");
		#endif

		contextp->statsPrintSummary();

		return 0;
}