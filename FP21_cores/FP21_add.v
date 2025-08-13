`include "FP21_cores/definitions.vh"

/*
Inputs are unpacked arrays.
Only works for Normalized non-special case numbers.
Needs propper zero handling at least.

The module is pipelined.
*/

module FP21_add (
	clk,
	sign_a,
	sign_b,
	frac_a,
	frac_b,
	exp_a,
	exp_b,

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
output reg [`frac:0] frac_c_out;


reg [`exp:0] exp_diff, exp_diff_abs, exp_greater, exp_greater_dl, exp_greater_dl2, exp_greater_dl3, exp_greater_dl4, exp_greater_dl5, exp_greater_dl6;
reg [`exp:0] exp_greater_normalized, exp_greater_normalized_dl, exp_greater_normalized_dl2;
reg sign_xor, sign_xor_dl, sign_xor_dl2;
reg sign_c, sign_c_dl, sign_c_dl2, sign_c_dl3, sign_c_dl4, sign_c_dl5, sign_c_dl6, sign_c_dl7, sign_c_dl8, sign_c_dl9;

reg [`frac:0] frac_to_be_shifted, frac_to_be_shifted_dl, frac_to_be_bypassed, frac_to_be_bypassed_dl, frac_to_be_bypassed_dl2, frac_to_be_bypassed_dl3;

reg [(`frac*2)+1:0] frac_shifted;
reg [(`frac*2)+3:0] frac_shifted_inverted;

/* verilator lint_off UNUSEDSIGNAL */
reg [(`frac*2)+3:0] frac_combined, frac_combined_abs, frac_combined_abs_dl, frac_normalized;
/* verilator lint_on UNUSEDSIGNAL */

reg [`frac:0] frac_normalized_trunk;
reg [`frac+1:0] frac_normalized_trunk_rounded;

reg round_up, round, guard, sticky;


sixteen_bit_LZC LZC(.clk(clk), .array(frac_combined_abs[(`frac*2)+3:(`frac*2)-12]), .value(lzc));
reg [3:0] lzc;

//11 pipeline stages
always @(posedge clk) begin
	/*===========================================================*/
	exp_diff <= exp_a - exp_b;
	exp_greater <= (exp_a > exp_b) ? exp_a : exp_b;
	
	frac_to_be_shifted <= (exp_a > exp_b) ? frac_b : frac_a;
	frac_to_be_bypassed <= (exp_a > exp_b) ? frac_a : frac_b;

	sign_xor <= sign_a ^ sign_b;
	sign_c <= (exp_a == exp_b) ? ((frac_a > frac_b) ? sign_a : sign_b) : ((exp_a > exp_b) ? sign_a : sign_b);  

	/*===========================================================*/
	sign_xor_dl <= sign_xor;
	sign_c_dl <= sign_c;

	exp_greater_dl <= exp_greater;
	exp_diff_abs <= exp_diff[`exp] ? (~exp_diff + 1'b1) : exp_diff;

	frac_to_be_shifted_dl <= frac_to_be_shifted;
	frac_to_be_bypassed_dl <= frac_to_be_bypassed;

	/*===========================================================*/
	sign_xor_dl2 <= sign_xor_dl;

	exp_greater_dl2 <= exp_greater_dl;

	frac_shifted <= {frac_to_be_shifted_dl, `frac'b0, 1'b0} >> exp_diff_abs; //2x size of frac_to_be_shifted
	frac_to_be_bypassed_dl2 <= frac_to_be_bypassed_dl;

	sign_c_dl2 <= sign_c_dl;

	/*===========================================================*/
	exp_greater_dl3 <= exp_greater_dl2;

	frac_shifted_inverted <= sign_xor_dl2 ? (~({2'b0, frac_shifted}) + 1'b1) : {2'b0, frac_shifted};
	frac_to_be_bypassed_dl3 <= frac_to_be_bypassed_dl2;

	sign_c_dl3 <= sign_c_dl2;

	/*===========================================================*/
	exp_greater_dl4 <= exp_greater_dl3;

	frac_combined <= {2'b0, frac_to_be_bypassed_dl3, `frac'b0, 1'b0} + frac_shifted_inverted;

	sign_c_dl4 <= sign_c_dl3;

	/*===========================================================*/
	exp_greater_dl5 <= exp_greater_dl4;

	frac_combined_abs <= frac_combined[(`frac*2)+3] ? (~frac_combined + 1'b1) : frac_combined;

	sign_c_dl5 <= sign_c_dl4;

	/*===========================================================*/
	exp_greater_dl6 <= exp_greater_dl5;
	//LZC here
	frac_combined_abs_dl <= frac_combined_abs;

	sign_c_dl6 <= sign_c_dl5;

	/*===========================================================*/
	exp_greater_normalized <= (exp_greater_dl6 - {5'b0, lzc}) + 2;
	
	frac_normalized <= frac_combined_abs_dl << lzc; //UNUSED SIGNAL WARNING

	guard <= {(frac_combined_abs_dl << lzc)}[`frac+2];
	round <= {(frac_combined_abs_dl << lzc)}[`frac+1];
	sticky <= |{(frac_combined_abs_dl << lzc)}[`frac:0];

	sign_c_dl7 <= sign_c_dl6;

	/*===========================================================*/
	exp_greater_normalized_dl <= exp_greater_normalized;

	round_up <= guard & (round | sticky | frac_normalized[0]);
	//may need normalization after guard round sticky.
	frac_normalized_trunk <= frac_normalized[(`frac*2)+3:(`frac+3)];

	sign_c_dl8 <= sign_c_dl7;

	/*===========================================================*/
	exp_greater_normalized_dl2 <= exp_greater_normalized_dl;

	frac_normalized_trunk_rounded <= {1'b0, frac_normalized_trunk} + {{(`frac){1'b0}}, round_up};

	sign_c_dl9 <= sign_c_dl8;

	/*===========================================================*/
	sign_c_out <= sign_c_dl9;

	{1'b0, frac_c_out} <= frac_normalized_trunk_rounded >> frac_normalized_trunk_rounded[`frac+1];

	exp_c_out <= exp_greater_normalized_dl2 + {`exp'b0, frac_normalized_trunk_rounded[`frac+1]};


end

endmodule
