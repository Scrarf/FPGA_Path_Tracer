#include <memory>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include <math.h>
#include <stdio.h>
#include <random>
#include <queue>
#include "functions.h"

#include "Vfifo_36bit_sync.h"

//For long error rate testing.
//#define SIM_STEPS 1000000000

//For fast confirmation
#define SIM_STEPS 100000

#define PIPELINE_DELAY 10

double sc_time_stamp() { return 0; }

struct str{
	int time, val;
};

std::queue<str> expected_output;

int error_count;
double val_a;

int main(int argc, char** argv) {

	printf("LETS START!!! WEEEE!!!!!\n");

	const std::unique_ptr<VerilatedContext> contextp{new VerilatedContext};

	contextp->debug(0);
	contextp->randReset(2);
	contextp->traceEverOn(true);
	contextp->commandArgs(argc, argv);

	const std::unique_ptr<Vfifo_36bit_sync> fifo_36bit_sync{new Vfifo_36bit_sync{contextp.get(), "fifo_36bit_sync"}};

	fifo_36bit_sync->clk = 0;
    
	
	while (!contextp->gotFinish()) {
			contextp->timeInc(1);
	
		fifo_36bit_sync->clk = !fifo_36bit_sync->clk;
		fifo_36bit_sync->rd_en = 0;
		fifo_36bit_sync->wr_en = 0;

		
	
		if (fifo_36bit_sync->clk) {

			val_a = val_a++;

			fifo_36bit_sync->wr_data = val_a;
			fifo_36bit_sync->wr_en = 1;

			expected_output.push({contextp->time() + ((PIPELINE_DELAY-1)*2), val_a});
		}

		fifo_36bit_sync->eval();
 	  	
 	  	if (fifo_36bit_sync->clk && ((contextp->time() > ((PIPELINE_DELAY-1)*2)  ))) {
 	  		str expected_result;

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

 	  		

 	  		//if (abs(expected_result.ans - ans_to_double) > 0.1) {
 	  			printf("t=%d val=%d\n",
 	  			contextp->time(),
 	  			fifo_36bit_sync->rd_data);

 	  			fifo_36bit_sync->rd_en = 1;

 	  			//error_count++;
 	  		//}

 	  	}
 	  	

 	  	fifo_36bit_sync->eval();


 	  	if ((contextp->time()) > SIM_STEPS) {
 	  		contextp->gotFinish(true);
 	  	}
 	  	
	}
	//printf("error_rate: %f%\n", error_count / ((double)(SIM_STEPS - PIPELINE_DELAY - 1) / 2) * 100.0);
	
	fifo_36bit_sync->final();

	//Coverage analysis (--coverage)
	#if VM_COVERAGE
 	  	contextp->coveragep()->write("logs/coverage/coverage.dat");
	#endif

	contextp->statsPrintSummary();

	return 0;
}