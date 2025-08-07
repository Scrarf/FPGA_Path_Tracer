#include <memory>
#include <verilated.h>
#include "../obj_dir/Vsixteen_bit_LZC.h"
#include <verilated_vcd_c.h>
#include <math.h>
#include <stdio.h>
#include <random>
#include <queue>
#include "functions.h"

#include "Vsixteen_bit_LZC.h"

//For long error rate testing.
//#define SIM_STEPS 1000000000

//For fast confirmation
#define SIM_STEPS 1000000

#define PIPELINE_DELAY 1

double sc_time_stamp() { return 0; }

struct queue_dl {
	int time;
	unsigned int array;
	unsigned int value;
};

std::queue<queue_dl> expected_output;

int error_count = 0;

unsigned int array = 0;

unsigned int random_LZC(unsigned int* out) {
    unsigned int array = rand() & 0xFFFF;  // 16-bit mask
    *out = 0;

    for (int i = 15; i >= 0; i--) {
        if ((array >> i) & 1) {
            break;
        } else {
            (*out)++;
        }
    }

    return array;
}

int main(int argc, char** argv) {

		printf("LETS START!!! WEEEE!!!!!\n");

		const std::unique_ptr<VerilatedContext> contextp{new VerilatedContext};

		contextp->debug(0);
		contextp->randReset(2);
		contextp->traceEverOn(true);
		contextp->commandArgs(argc, argv);

		const std::unique_ptr<Vsixteen_bit_LZC> sixteen_bit_LZC{new Vsixteen_bit_LZC{contextp.get(), "sixteen_bit_LZC"}};

		sixteen_bit_LZC->clk = 0;
    	
		
		while (!contextp->gotFinish()) {
				contextp->timeInc(1);
	
			sixteen_bit_LZC->clk = !sixteen_bit_LZC->clk;

			
	
			if (sixteen_bit_LZC->clk) {

				
				unsigned int value = 0;
				sixteen_bit_LZC->array = random_LZC(&value);

				expected_output.push({contextp->time() + ((PIPELINE_DELAY-1)*2), sixteen_bit_LZC->array, value});
			}

			sixteen_bit_LZC->eval();
 		  	
 		  	if (sixteen_bit_LZC->clk && ((contextp->time() > ((PIPELINE_DELAY-1)*2)  ))) {

 		  		queue_dl expected_result = {0, 0, 0};

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


 		  		if (sixteen_bit_LZC->value != expected_result.value) {
 		  		printf("t=%d et=%d array=%b expt=%d rly=%d \n",
 		  			contextp->time(),
 		  			expected_result.time,
 		  			expected_result.array,
 		  			expected_result.value,
 		  			sixteen_bit_LZC->value);

 		  			error_count++;
 		  		}

 		  		

 		  	}
 		  	

 		  	sixteen_bit_LZC->eval();


 		  	if ((contextp->time()) > SIM_STEPS) {
 		  		contextp->gotFinish(true);
 		  	}
 		      
		}
		printf("error_rate: %f%\n", error_count / ((double)(SIM_STEPS - PIPELINE_DELAY - 1) / 2) * 100.0);
		
		sixteen_bit_LZC->final();

		//Coverage analysis (--coverage)
		#if VM_COVERAGE
 		  Verilated::mkdir("logs");
 		  contextp->coveragep()->write("logs/coverage.dat");
		#endif

		contextp->statsPrintSummary();

		return 0;
}