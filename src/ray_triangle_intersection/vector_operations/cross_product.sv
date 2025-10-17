`include "src/arithmetic_cores/definitions.vh"

/* Visit definitions.vh for macro definitions of `add and `mult */

module cross_product (
	input wire clk,
	input p_float3 a,
	input p_float3 b,
	output p_float3 c
);

//mult mult_0(clk, a.x, b.y, mult_0_net); //postprocessed macro example

`mult(mult_0, a.y, b.z);
`mult(mult_1, a.z, b.y);

`mult(mult_2, a.z, b.x);
`mult(mult_3, a.x, b.z);

`mult(mult_4, a.x, b.y);
`mult(mult_5, a.y, b.x);

//add add_0(clk, mult_0_net, `neg_p_float(mult_1_net), c.x);

`add(add_0, mult_0_net, `neg_p_float(mult_1_net));
`add(add_1, mult_2_net, `neg_p_float(mult_3_net));
`add(add_2, mult_4_net, `neg_p_float(mult_5_net));

assign c.x = add_0_net;
assign c.y = add_1_net;
assign c.z = add_2_net;

endmodule
