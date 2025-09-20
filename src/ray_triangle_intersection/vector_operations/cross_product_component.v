`include "src/FP21_cores/definitions.vh"

/*
A single axis component of the Cross product.
*/

/*
(a * b) - (c * d);
*/

module cross_product_component (
	sign_a,
	sign_b,
	sign_c,
	sign_d,

	exp_a,
	exp_b,
	exp_c,
	exp_d,

	frac_a,
	frac_b,
	frac_c,
	frac_d,

	sign_out,
	exp_out,
	frac_out,

	clk
	
);

input wire sign_a, sign_b, sign_c, sign_d;
input wire [(`exp):0] exp_a, exp_b, exp_c, exp_d;
input wire [(`frac):0] frac_a, frac_b, frac_c, frac_d;
input wire clk;

output reg sign_out;
output reg [`exp:0] exp_out;
output reg [`frac:0] frac_out;


FP21_mult mult_0(.clk(clk), .sign_a(sign_a), .sign_b(sign_b), .sign_c_out(mult_0_sign_c),
							.exp_a(exp_a), .exp_b(exp_b), .exp_c_out(mult_0_exp_c),
							.frac_a(frac_a), .frac_b(frac_b), .frac_c_out(mult_0_frac_c));

FP21_mult mult_1(.clk(clk), .sign_a(sign_c), .sign_b(sign_d), .sign_c_out(mult_1_sign_c),
							.exp_a(exp_c), .exp_b(exp_d), .exp_c_out(mult_1_exp_c),
							.frac_a(frac_c), .frac_b(frac_d), .frac_c_out(mult_1_frac_c));

wire mult_0_sign_c, mult_1_sign_c;
wire [`exp:0] mult_0_exp_c, mult_1_exp_c;
wire [`frac:0] mult_0_frac_c, mult_1_frac_c;


FP21_add add_0(.clk(clk), .sign_a(mult_0_sign_c), .sign_b(mult_1_sign_c), .sign_c_out(sign_out),
							.exp_a(mult_0_exp_c), .exp_b(mult_1_exp_c), .exp_c_out(exp_out),
							.frac_a(mult_0_frac_c), .frac_b(mult_1_frac_c), .frac_c_out(frac_out));

endmodule


