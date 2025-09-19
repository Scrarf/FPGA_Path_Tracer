
#pragma once
#include <verilated.h>

extern int SIM_STEPS;
extern int PIPELINE_DELAY;

void tb_init(VerilatedContext* contextp);
void tb_eval(VerilatedContext* contextp, int* error_count, int* itteration_count);
void tb_end();
