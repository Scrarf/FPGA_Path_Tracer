`include "FP21_cores/definitions.vh"

/*
Inputs are unpacked arrays.
Only works for Normalized non special case numbers.
*/

module FP21_add (
	clk,
	sign_a,
	sign_b,
	frac_a,
	frac_b,
	exp_a,
	exp_b

	sign_c_out,
	exp_c_out,
	frac_c_out
);

input wire sign_a, sign_b;
input wire signed [`exp:0] exp_a, exp_b;
input wire [`frac:0] frac_a, frac_b;
input wire clk;

output reg sign_c_out;
output reg [`exp:0] exp_c_out;
output reg [`frac:0]frac_c_out;


reg [(`frac + 1):0] frac_combined;


always @(posedge clk) begin
	/*===========================================================*/
	exp_diff <= exp_a - exp_b;
	exp_cmp <= exp_a > exp_b;
	sign_xor <= sign_a ^ sign_b;

	frac_a_dl <= frac_a;
	frac_b_dl <= frac_b;
	/*===========================================================*/
	sign_xor_dl <= sign_xor;

	exp_diff_abs <= exp_diff[`exp] ? (~(exp_diff) + 1'b1);

	bigger_exp <= (exp_cmp) ? exp_a_dl : exp_b_dl;

	frac_to_be_shifted <= (exp_cmp) ? frac_b_dl : frac_a_dl;
	frac_to_be_bypassed <= (exp_cmp) ? frac_a_dl : frac_b_dl;

	/*===========================================================*/
	sign_xor_dl2 <= sign_xor_dl;
	frac_to_be_bypassed_dl <= frac_to_be_bypassed;

	frac_shifted <= frac_to_be_shifted >> exp_diff_abs;

	

	/*===========================================================*/
	frac_to_be_bypassed_dl2 <= frac_to_be_bypassed_dl;
	frac_possibly_inverted <= sign_xor_dl2 ? (~(frac_shifted) + 1'b1) : frac_shifted;


	/*===========================================================*/

	frac_combined <= frac_to_be_bypassed_dl2 + frac_possibly_inverted;

	/*===========================================================*/


end

endmodule
