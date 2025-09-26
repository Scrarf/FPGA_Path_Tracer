`include "src/arithmetic_cores/definitions.vh"


module cross_product (
	input wire clk,
	input p_float3 a,
	input p_float3 b,
	output p_float3 c
);


mult mult_0(clk, a.y, b.z, net[0]);
mult mult_1(clk, a.z, b.y, net[1]);

mult mult_2(clk, a.z, b.x, net[2]);
mult mult_3(clk, a.x, b.z, net[3]);

mult mult_4(clk, a.x, b.y, net[4]);
mult mult_5(clk, a.y, b.x, net[5]);

p_float [5:0] net;

add add_0(clk, net[0], {~net[1].sign, net[1].exp, net[1].frac}, c.x);
add add_1(clk, net[2], {~net[3].sign, net[3].exp, net[3].frac}, c.y);
add add_2(clk, net[4], {~net[5].sign, net[5].exp, net[5].frac}, c.z);


endmodule
