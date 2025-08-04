/*
Inputs are unpacked arrays.
Only works for Normalized non special case numbers.
*/

`include "FP21_cores/definitions.vh"

module FP21_add (
	clk,
	sign_a,
	sign_b,
	frac_a,
	frac_b,
	exp_a,
	exp_b

	/*output*/
);

input wire sign_a, sign_b;
input wire [11:0] frac_a, frac_b;
input wire [7:0] exp_a, exp_b;
input wire clk;

reg [8:0] exp_norm_a;
reg [8:0] exp_norm_b;
reg needs_swap;
reg sign_dl_a;
reg sign_dl_b;
reg [11:0] frac_dl_a;
reg [11:0] frac_dl_b;

reg [8:0] exp_diff;
reg [8:0] exp_norm_swap_a;
reg [8:0] exp_norm_swap_b;
reg sign_swap_a;
reg sign_swap_b;
reg [11:0] frac_swap_a;
reg [11:0] frac_swap_b;
reg [12:0] frac_norm_a;
reg [12:0] frac_norm_b;
reg [14:0] comb_frac;



always @(posedge clk) begin
	/*===========================================================*/
	needs_swap <= exp_a > exp_b;
	exp_diff <= exp_a - exp_b;

	sign_dl_a <= sign_a;
	sign_dl_b <= sing_b;

	frac_dl_a <= frac_a;
	frac_dl_b <= frac_b;

	exp_dl_a <= exp_a;
	exp_dl_b <= exp_b;
 
	/*===========================================================*/
	exp_diff_dl <= exp_diff;

	exp_final <= needs_swap ? exp_a : exp_b;

	exp_norm_swap_a <= needs_swap ? exp_b : exp_a;
	exp_norm_swap_b <= needs_swap ? exp_a : exp_b;

	sign_swap_a <= needs_swap ? sign_dl_b : sign_dl_a;
	sign_swap_b <= needs_swap ? sign_dl_a : sign_dl_b;

	frac_swap_a <= needs_swap ? frac_dl_b : frac_dl_a;
	frac_swap_b <= needs_swap ? frac_dl_a : frac_dl_b;

	sign_xor <= sign_dl_a ^ sign_dl_b;
	sign_and <= sign_dl_a & sign_dl_b;

	/*===========================================================*/
	frac_norm_a <= {1'b1, (frac_swap_a >> exp_diff_dl)};
	frac_norm_b <= (1'b1, frac_swap_b);

	exp_final_dl <= exp_final;

	sign_xor_dl <= sign_xor;
	sign_and_dl <= sign_and;

	/*===========================================================*/
	comb_frac <= sign_xor_dl ? (frac_norm_b + frac_norm_a) : (frac_norm_b - frac_norm_a);

	exp_final_dl2 <= exp_final_dl;



end

endmodule
