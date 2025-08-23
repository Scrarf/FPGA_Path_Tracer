`include "FP21_cores/definitions.vh"

module FP21_special_case_check (
	FP_21,

	zero,
	nan,
	denormal,
	neg_inf,
	pos_inf
);


input [(`exp + `frac):0] FP_21;

output zero, nan, denormal, neg_inf, pos_inf;


`define exp_arr FP_21[(`exp + `frac - 1):`frac]
`define sign_arr FP_21[`exp + `frac]
`define frac_arr FP_21[(`fraq - 1):0]


assign zero = ~|(`exp_arr) & ~|(`frac_arr);
assign nan = &(`exp_arr) & |(`frac_arr);
assign pos_inf = &(`exp_arr) & ~|(`frac_arr) & ~(`sign_arr);
assign neg_inf = &(`exp_arr) & ~|(`frac_arr) & (`sign_arr);
assign denormal = ~|(`exp_arr) & |(`frac_arr);

endmodule



