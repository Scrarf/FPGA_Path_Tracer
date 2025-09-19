#include <memory>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include <math.h>
#include <stdio.h>
#include <random>
#include <queue>
#include "functions.h"

#include "Vcross_product_component.h"

//For long error rate testing.
//#define SIM_STEPS 1000000000

//For fast confirmation
#define SIM_STEPS 100000

#define PIPELINE_DELAY 18

//no need for VCD dump since multiplication is simple enough

double sc_time_stamp() { return 0; }

struct queue_dl {
	int time;
	double a;
	double b;
	double ans;
};

std::queue<queue_dl> expected_output;

int error_count;
int sign_a, exp_a, frac_a;
int sign_b, exp_b, frac_b;
double val_a, val_b;

int main(int argc, char** argv) {

	printf("LETS START!!! WEEEE!!!!!\n");

	const std::unique_ptr<VerilatedContext> contextp{new VerilatedContext};

	contextp->debug(0);
	contextp->randReset(2);
	contextp->traceEverOn(true);
	contextp->commandArgs(argc, argv);

	const std::unique_ptr<Vcross_product_component> cross_product_component{new Vcross_product_component{contextp.get(), "cross_product_component"}};

	cross_product_component->clk = 0;
    
	
	while (!contextp->gotFinish()) {
			contextp->timeInc(1);
	
		cross_product_component->clk = !cross_product_component->clk;

		
	
		if (cross_product_component->clk) {

			val_a = random_double(-10, 10);
			to_int(val_a, &sign_a, &exp_a, &frac_a);
				
			val_b = random_double(-10, 10);
			to_int(val_b, &sign_b, &exp_b, &frac_b);

			val_c = random_double(-10, 10);
			to_int(val_c, &sign_c, &exp_c, &frac_c);
				
			val_d = random_double(-10, 10);
			to_int(val_d, &sign_d, &exp_d, &frac_d);

			cross_product_component->sign_a = sign_a;
			cross_product_component->sign_b = sign_b;
			ross_product_component->sign_b = sign_c;
			ross_product_component->sign_b = sign_d;

			cross_product_component->exp_a = exp_a;
			cross_product_component->exp_b = exp_b;
			cross_product_component->exp_b = exp_c;
			cross_product_component->exp_b = exp_d;

			cross_product_component->frac_a = frac_a;
			cross_product_component->frac_b = frac_b;
			cross_product_component->frac_a = frac_c;
			cross_product_component->frac_a = frac_d;

			expected_output.push({contextp->time() + ((PIPELINE_DELAY-1)*2), val_a, val_b, val_a * val_b});
		}

		cross_product_component->eval();
 	  	
 	  	if (cross_product_component->clk && ((contextp->time() > ((PIPELINE_DELAY-1)*2)  ))) {

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

 	  		double ans_to_double = to_double(cross_product_component->sign_c_out, cross_product_component->exp_c_out, cross_product_component->frac_c_out);

 	  		if (abs(expected_result.ans - ans_to_double) > 0.1) {
 	  		printf("t=%d et=%d a=%.16lf b=%.16lf expt=%.16lf rly=%.16lf \n",
 	  			contextp->time(),
 	  			expected_result.time,
 	  			expected_result.a,
 	  			expected_result.b,
 	  			expected_result.ans,
 	  			ans_to_double);

 	  			error_count++;
 	  			printf("sign_c=%b exp_c=%b frac_c=%b\n",cross_product_component->sign_c_out, cross_product_component->exp_c_out, cross_product_component->frac_c_out);
 	  		}

 	  		

 	  	}
 	  	

 	  	cross_product_component->eval();


 	  	if ((contextp->time()) > SIM_STEPS) {
 	  		contextp->gotFinish(true);
 	  	}
 	  	
	}
	printf("error_rate: %f%\n", error_count / ((double)(SIM_STEPS - PIPELINE_DELAY - 1) / 2) * 100.0);
	
	cross_product_component->final();

	//Coverage analysis (--coverage)
	#if VM_COVERAGE
 	  	//Verilated::mkdir("logs");
 	  	contextp->coveragep()->write("logs/coverage/coverage.dat");
	#endif

	contextp->statsPrintSummary();

	return 0;
}