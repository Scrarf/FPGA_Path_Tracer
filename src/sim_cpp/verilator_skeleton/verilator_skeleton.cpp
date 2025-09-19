#include <verilated.h>
#include "verilator_if.h"

double sc_time_stamp() {return 0;}

int error_count;

int main(int argc, char** argv) {
    const std::unique_ptr<VerilatedContext> contextp{new VerilatedContext};

    contextp->debug(0);
    contextp->randReset(2);
    contextp->traceEverOn(true);
    contextp->commandArgs(argc, argv);

    tb_init(contextp.get());

    while (!contextp->gotFinish()) {
        contextp->timeInc(1);
        tb_eval(contextp.get(), &error_count);

        if (contextp->time() >= SIM_STEPS) {
            contextp->gotFinish(true);
        }
    }

    printf("Error rate: %f%\n", error_count / ((double)(SIM_STEPS - PIPELINE_DELAY - 1) / 2) * 100.0);
    printf("%d\n", error_count);

    tb_report();

    contextp->statsPrintSummary();
    printf("ITS DONE");

    return 0;
}