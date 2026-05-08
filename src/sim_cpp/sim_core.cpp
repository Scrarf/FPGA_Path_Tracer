#include <memory>
#include <queue>
#include <cmath>
#include <cstdio>
#include <verilated.h>
#include "Vcore.h"
#include "Vcore___024root.h"

Vcore* dut;


uint32_t code[256];

void generate_code() {
	
	code[1] = 0x08000100;
	code[2] = 0x08010100;

	code[3] = 0x01030900;
	code[4] = 0x0A000300;

	code[9] = 0x01070100;
	
	return;
}

int main(int argc, char** argv) {
    const std::unique_ptr<VerilatedContext> contextp{new VerilatedContext};

    contextp->debug(0);
    contextp->randReset(2);
    contextp->traceEverOn(true);
    contextp->commandArgs(argc, argv);

	
	dut = new Vcore(contextp.get(), "core");

	generate_code();

	memcpy(&(dut->rootp->core__DOT__IMEM), &code, 256);

	dut->rootp->core__DOT__r[7] = 0;

	dut->rootp->core__DOT__r[0] = 0;
	dut->rootp->core__DOT__r[1] = 1;
	dut->rootp->core__DOT__r[2] = 0;
	
	dut->rst = 1;
	dut->clk = 1;
	dut->eval();
	
	dut->clk = 0;
	dut->rst = 0;
	dut->eval();

	
    for (int i = 0; i < 50; i++) {
        printf("r[7]: %d\n", dut->rootp->core__DOT__r[7]);
        printf("r[0]: %d\n", dut->rootp->core__DOT__r[0]);
        printf("r[1]: %d\n", dut->rootp->core__DOT__r[1]);
        printf("\n");
        dut->clk = 1; dut->eval();
        dut->clk = 0; dut->eval();
        
    }

	printf("MMIO[0]: %d\n", dut->rootp->core__DOT__MMIO[0]);

	delete(dut);

    //contextp->statsPrintSummary();
    return 0;
}

