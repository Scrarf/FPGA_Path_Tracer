#include <verilated.h>
#include "verilator_if.h"

double sc_time_stamp() {return 0;}

int error_count = 0;
int itteration_count = 0;

int main(int argc, char** argv) {
    const std::unique_ptr<VerilatedContext> contextp{new VerilatedContext};

    contextp->debug(0);
    contextp->randReset(2);
    contextp->traceEverOn(true);
    contextp->commandArgs(argc, argv);

    tb_init(contextp.get());

    while (!contextp->gotFinish()) {
        
        tb_eval(contextp.get(), &error_count, &itteration_count);
        contextp->timeInc(1);

        if (contextp->time() >= SIM_STEPS) {
            contextp->gotFinish(true);
        }
    }

    printf("Error rate: %f%\n", ((double)error_count / (double)itteration_count) * 100.00);
    printf("Error count: %d\nItteration count: %d.\n", error_count, itteration_count);

    tb_end();

    contextp->statsPrintSummary();
    return 0;
}