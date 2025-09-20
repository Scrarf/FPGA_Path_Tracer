`include "src/FP21_cores/definitions.vh"


module cross_product (
	input sign_in [11:0],
	input [`exp:0] exp_in [11:0],
	input [`frac:0] frac_in [11:0],

	output sign_out [2:0],
	output [`exp:0] exp_out [2:0],
	output [`frac:0] frac_out [2:0],

	input wire clk

);

wire net_sign [5:0];
wire [`exp:0] net_exp [5:0];
wire [`frac:0] net_frac [5:0];

genvar i;
generate
	for (i = 0; i < 6; i++) begin
		FP21_mult mult0(.clk(clk), .sign_a(sign_in[(2*i)]), .sign_b(sign_in[(2*i)+1]), .sign_c_out(net_sign[i]),
								   .exp_a(exp_in[(2*i)]), .exp_b(exp_in[(2*i)+1]), .exp_c_out(net_exp[i]),
								   .frac_a(frac_in[(2*i)]), .frac_b(frac_in[(2*i)+1]), .frac_c_out(net_frac[i]));


	end
endgenerate

generate
	for (i = 0; i < 3; i++) begin
		FP21_add add0(.clk(clk), .sign_a(net_sign[(2*i)]), .sign_b(net_sign[(2*i)+1]), .sign_c_out(sign_out[i]),
								 .exp_a(net_exp[(2*i)]), .exp_b(net_exp[(2*i)+1]), .exp_c_out(exp_out[i]),
								 .frac_a(net_frac[(2*i)]), .frac_b(net_frac[(2*i)+1]), .frac_c_out(frac_out[i]));
	end
endgenerate


endmodule
