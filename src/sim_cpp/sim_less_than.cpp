#include <memory>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include <math.h>
#include <stdio.h>
#include <random>
#include <queue>
#include "functions.h"

#include "VFP21_less_than.h"

//For long error rate testing.
//#define SIM_STEPS 1000000000
//For fast confirmation
#define SIM_STEPS 100000

#define PIPELINE_DELAY 1

double sc_time_stamp() { return 0; }

struct queue_dl {
	int time;
	double a;
	double b;
	bool ans;
};

std::queue<queue_dl> expected_output;

int main(int argc, char** argv) {

		printf("LETS START!!! WEEEE!!!!!\n");

		const std::unique_ptr<VerilatedContext> contextp{new VerilatedContext};

		contextp->debug(0);
		contextp->randReset(2);
		contextp->traceEverOn(true);
		contextp->commandArgs(argc, argv);

		const std::unique_ptr<VFP21_less_than> FP21_less_than{new VFP21_less_than{contextp.get(), "FP21_less_than"}};

		FP21_less_than->clk = 0;
    	

		int error_count = 0;

		int sign_a, exp_a, frac_a;
		int sign_b, exp_b, frac_b;

		double val_a = 0;
		double val_b = 0;

		while (!contextp->gotFinish()) {
				contextp->timeInc(1);
	
			FP21_less_than->clk = !FP21_less_than->clk;

			
	
			if (FP21_less_than->clk) {

				val_a = random_double(-100.0, 100.0);
				to_int(val_a, &sign_a, &exp_a, &frac_a);
					
				val_b = random_double(-100.0, 100.0);
				to_int(val_b, &sign_b, &exp_b, &frac_b);

				FP21_less_than->sign_a = sign_a;
				FP21_less_than->sign_b = sign_b;
				FP21_less_than->exp_a = exp_a;
				FP21_less_than->exp_b = exp_b;
				FP21_less_than->frac_a = frac_a;
				FP21_less_than->frac_b = frac_b;

				expected_output.push({contextp->time() + (PIPELINE_DELAY*2), val_a, val_b, val_a < val_b});
			}
			
		
 		  	
 		  	if (FP21_less_than->clk && contextp->time() > (PIPELINE_DELAY*2)) {

 		  		queue_dl expected_result = {0, 0, 0, 0};

 		  		if (!expected_output.empty()) {
 		  			expected_result = expected_output.front();
 		  			expected_output.pop();
 		  		} else {
 		  			printf("QUEUE_IS_EMPTY");
 		  			contextp->gotFinish(true);
 		  		}
 		  		if (expected_result.time != contextp->time()) {
 		  			printf("SYNCHRONIZATION_ERROR!\n");
 		  			contextp->gotFinish(true);
 		  		}

 		  		if (expected_result.ans != FP21_less_than->result) {
 		  		printf("time=%d val_a=%f val_b=%f expectation=%d reality=%d \n",
 		  			contextp->time(),
 		  			expected_result.a,
 		  			expected_result.b,
 		  			expected_result.ans,
 		  			FP21_less_than->result);

 		  			error_count++;
 		  		}

 		  	}

 		  	FP21_less_than->eval();


 		  	if ((contextp->time()) > SIM_STEPS) {
 		  		contextp->gotFinish(true);
 		  	}
 		      
		}
		printf("error_rate: %f%\n", (double)( (double)error_count / (double)SIM_STEPS * 100.0 * 2));
		//error_rate: 0.002265%
		
		FP21_less_than->final();

		//Coverage analysis (--coverage)
		#if VM_COVERAGE
 		  Verilated::mkdir("logs");
 		  contextp->coveragep()->write("logs/coverage.dat");
		#endif

		contextp->statsPrintSummary();

		return 0;
}