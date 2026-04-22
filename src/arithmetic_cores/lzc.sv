/*
Leading zero counter.

*/


module lzc (
    input wire clk,
    input wire [`frac:0] array,
    output reg [4:0] value
);

    wire [11:0] q;
    wire [5:0] a;
    wire [2:0] q2;
    wire [1:0] out;

    four_bit_LZC LZC_0(.x(array[3:0]), .q(q[1:0]), .a(a[0]));
    four_bit_LZC LZC_1(.x(array[7:4]), .q(q[3:2]), .a(a[1]));
    four_bit_LZC LZC_2(.x(array[11:8]), .q(q[5:4]), .a(a[2]));
    four_bit_LZC LZC_3(.x(array[15:12]), .q(q[7:6]), .a(a[3]));
    four_bit_LZC LZC_4(.x(array[19:16]), .q(q[9:8]), .a(a[4]));
    four_bit_LZC LZC_5(.x(array[23:20]), .q(q[11:10]), .a(a[5]));

    six_bit_LZE LZE_0(.x(a), .q(q2));

    eight_to_one_mux mux_0(.in({q[10], q[8], q[6], q[4], q[2], q[0]}), .sel(q2), .out(out[0]));
    eight_to_one_mux mux_1(.in({q[11], q[9], q[7], q[5], q[3], q[1]}), .sel(q2), .out(out[1]));

always @(posedge clk) begin
    value <= {q2, out};
end

endmodule

/* verilator lint_off DECLFILENAME */
module four_bit_LZC (
    input wire [3:0] x,
    output wire [1:0] q,
    output wire a
);

assign a = ~|x;
assign q[1] = ~(x[3] | x[2]);
assign q[0] = (~x[1] | x[2]) & (~x[3]);

endmodule
/* verilator lint_on DECLFILENAME */

/* verilator lint_off UNUSEDSIGNAL */
module six_bit_LZE (
    input wire [5:0] x,
    output reg [2:0] q
);

//assign q[1] = x[3] & x[2];
//assign q[0] = (x[3] & ~x[2]) | (x[3] & x[2] & x[1] & ~x[0]) | &x;

assign q[2] = &x[5:2];
assign q[1] = &x[5:4] & ~x[3] | (&x[5:3] & ~x[2]);
assign q[0] = (x[5] & ~x[4]) | (&x[5:3] & ~x[2]) | (&x[5:1]);

endmodule
/* verilator lint_on UNUSEDSIGNAL */

module eight_to_one_mux (
    input wire [5:0] in,
    input wire [2:0] sel,
    output reg out
);

always @(*) begin
    case (sel)
        3'b000: out = in[5];
        3'b001: out = in[4];
        3'b010: out = in[3];
        3'b011: out = in[2];
        3'b100: out = in[1];
        3'b101: out = in[0];
        default: out = 1'b0;
    endcase
end

endmodule
