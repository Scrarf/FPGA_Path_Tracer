`include "FP21_cores/definitions.vh"

/*
Inputs are unpacked arrays.
Only works for Normalized non special case numbers.
*/

/*
Works perfectly so far according to testbench.
May need optimisation later.
*/


module FP21_mult (
	clk,
	sign_a,
	sign_b,
	frac_a,
	frac_b,
	exp_a,
	exp_b,

	sign_c_out,
	frac_c_out,
	exp_c_out
);

input wire sign_a, sign_b;
input wire [(`frac):0] frac_a, frac_b;
input wire [(`exp):0] exp_a, exp_b;
input wire clk;

output reg sign_c_out;
output reg [`frac:0] frac_c_out;
output reg [`exp:0] exp_c_out;

reg sign_c;
reg [(`exp):0] exp_c;
reg [((`frac*2)+1):0] prod;
reg [((`frac*2)):0] shift_prod;
reg [(`exp):0] norm_exp_c, norm_exp_c_dl, norm_exp_c_dl2, norm_exp_c_dl3;

reg [(`frac):0] prod_trunk_dl;
reg [(`frac):0] prod_trunk;

reg guard, round, sticky;
reg round_up;
reg sign_c_dl, sign_c_dl2, sign_c_dl3, sign_c_dl4;

reg [(`frac + 1):0] frac_c_rounded;

//6 pipeline stages.
always @(posedge clk) begin
	/*===========================================================*/
	sign_c <= sign_a ^ sign_b;
	exp_c <= exp_a + exp_b;
	prod <= frac_a * frac_b;

	/*===========================================================*/
	sign_c_dl <= sign_c;

	{1'b0, shift_prod} <= prod >> prod[(`frac*2)+1];
	//shift_prod <= prod[(`frac*2)+1] ? prod[(`frac*2+1):1] : prod[(`frac*2):0];
	//^ 2 identical lines of code logically but the first one is better.

	norm_exp_c <= exp_c + {8'b0, prod[(`frac*2)+1]};

	/*===========================================================*/
	sign_c_dl2 <= sign_c_dl;
	norm_exp_c_dl <= norm_exp_c;

	prod_trunk <= shift_prod[((`frac*2)):(`frac)];

	guard <= shift_prod[(`frac - 1)];
	round <= shift_prod[(`frac - 2)];
	sticky <= |shift_prod[(`frac - 3):0];

	/*===========================================================*/
	sign_c_dl3 <= sign_c_dl2;
	norm_exp_c_dl2 <= norm_exp_c_dl;
	prod_trunk_dl <= prod_trunk;

	round_up <= guard & (round | sticky | prod_trunk[0]);

	/*===========================================================*/
	sign_c_dl4 <= sign_c_dl3;
	norm_exp_c_dl3 <= norm_exp_c_dl2;

	frac_c_rounded <= prod_trunk_dl + {12'b0, round_up}; 

	/*===========================================================*/
	sign_c_out <= sign_c_dl4;
	exp_c_out <= norm_exp_c_dl3 + {8'b0, frac_c_rounded[`frac+1]};

	{1'b0, frac_c_out} <= frac_c_rounded >> frac_c_rounded[`frac+1];
end

endmodule
