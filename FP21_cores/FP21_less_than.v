`include "FP21_cores/definitions.vh"

/*
Tested but gives error_rate: 0.0022% due to precision errors.
Works with both packed and unpacked FP21s.
*/

module FP21_less_than (
	clk,

	sign_a,
	exp_a,
	frac_a,
	sign_b,
	exp_b,
	frac_b,
	result
);

input wire clk;

input wire sign_a;
input wire signed [`exp:0] exp_a;
input wire [`frac:0] frac_a;

input wire sign_b;
input wire signed [`exp:0] exp_b;
input wire [`frac:0] frac_b;

output reg result;


//1 pipeline stage
always @(posedge clk) begin
	result <= ((sign_a ^ sign_b) ? sign_a :
		 	  ((exp_a < exp_b) ? 1'b1 :
		 	  ((frac_a < frac_b) & (exp_a == exp_b))) ^ (sign_a & sign_b));
end

endmodule
