//https://digitalsystemdesign.in/leading-zero-counter/?srsltid=AfmBOoqrazKKMYZyF0kMoMaOzXOUlEO176j6WIowqHvgiFvRWOfbKQDU
//https://github.com/pulp-platform/common_cells/blob/master/src/lzc.sv
module 16bit_LZC (
	clk,

	array,
	value
);
input wire clk;

input reg [15:0] array;
output reg [3:0] value;


wire [7:0] q;
wire [3:0] a;

wire [1:0] q2;

wire [1:0] out;


4bit_LZC LZC_0(.x(array[3:0]), .q(q[1:0]), .a(a[0]));
4bit_LZC LZC_1(.x(array[7:4]), .q(q[3:2]), .a(a[1]));
4bit_LZC LZC_2(.x(array[11:8]), .q(q[5:4]), .a(a[2]));
4bit_LZC LZC_3(.x(array[15:12]), .q(q[7:6]), .a(a[3]));

4bit_LZC LZC_4(.x(a[3:0]), .q(q2[1:0]), .a());

4to1mux mux_1(.in({q[0], q[2], q[4], q[6]}), .sel(q2[1:0]), .out(out[0]));
4to1mux mux_1(.in({q[1], q[3], q[5], q[7]}), .sel(q2[1:0]), .out(out[1]));



always @(posedge clk) begin
	value <= {out, q2};
	
end

endmodule


module 4bit_LZC (x, q, a);

input wire [3:0] x;
output wire [1:0] q;
output wire a;

assign a = ~|(x);
assign q[1] = ~(x[3] | x[2]);
assign (~x[3] & x[2]) | (~x[3] & ~x[1]);

endmodule

module 4to1mux (in, sel, out);
input wire [3:0] in;
input wire [1:0] sel;
output wire out;

assign out = sel[1] ? (sel[0] ? d : c) : (sel[0] ? b : a);

endmodule