#include <memory>
#include <verilated.h>
#include "../obj_dir/VFP21_mult.h"
#include <verilated_vcd_c.h>
#include <math.h>
#include <stdio.h>
#include <random>
#include "functions.h"

double sc_time_stamp() { return 0; }


int main(int argc, char** argv) {

		printf("LETS START!!! WEEEE!!!!!\n");

		const std::unique_ptr<VerilatedContext> contextp{new VerilatedContext};

		contextp->debug(0);
		contextp->randReset(2);
		contextp->traceEverOn(true);
		contextp->commandArgs(argc, argv);

		const std::unique_ptr<VFP21_mult> FP21_mult{new VFP21_mult{contextp.get(), "FP21_mult"}};


    int sign_a, exp_a, frac_a;
		double val_a = random_double(-10.0, 10.0);
		to_int(val_a, &sign_a, &exp_a, &frac_a);
		
		int sign_b, exp_b, frac_b;
		double val_b = random_double(-10.0, 10.0);
		to_int(val_b, &sign_b, &exp_b, &frac_b);
		
		FP21_mult->sign_a = sign_a;
		FP21_mult->sign_b = sign_b;
		FP21_mult->exp_a = exp_a;
		FP21_mult->exp_b = exp_b;
		FP21_mult->frac_a = frac_a;
		FP21_mult->frac_b = frac_b;

		while (!contextp->gotFinish()) {
				contextp->timeInc(1);
	
				FP21_mult->clk = !FP21_mult->clk;

				
	
				
	
 		  	FP21_mult->eval();
	
	
 		  	VL_PRINTF("[%" PRId64 "] clk=%x val_a=%f val_b=%f exp_answer=%f calc_answer=%f\n",
 		  	          contextp->time(),
 		  	          FP21_mult->clk,
 		  	          val_a,
 		  	          val_b,
 		  	          (val_a * val_b),
 		  	          to_double(FP21_mult->sign_c_out, FP21_mult->exp_c_out, FP21_mult->frac_c_out));
	
 		  	if ((contextp->time()) > 99) {
 		  		contextp->gotFinish(true);
 		  	}
 		      
		}

		FP21_mult->final();

		//Coverage analysis (--coverage)
		#if VM_COVERAGE
 		  Verilated::mkdir("logs");
 		  contextp->coveragep()->write("logs/coverage.dat");
		#endif

		contextp->statsPrintSummary();

		return 0;
}