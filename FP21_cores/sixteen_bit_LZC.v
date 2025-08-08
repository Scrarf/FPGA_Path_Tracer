
module sixteen_bit_LZC (
    input wire clk,
    input wire [15:0] array,
    output reg [3:0] value
);

    wire [7:0] q;
    wire [3:0] a;
    wire [1:0] q2;
    wire [1:0] out;

    four_bit_LZC LZC_0(.x(array[3:0]), .q(q[1:0]), .a(a[0]));
    four_bit_LZC LZC_1(.x(array[7:4]), .q(q[3:2]), .a(a[1]));
    four_bit_LZC LZC_2(.x(array[11:8]), .q(q[5:4]), .a(a[2]));
    four_bit_LZC LZC_3(.x(array[15:12]), .q(q[7:6]), .a(a[3]));

    four_bit_LZE LZE_0(.x(a), .q(q2));

    four_to_one_mux mux_0(.in({q[6], q[4], q[2], q[0]}), .sel(q2), .out(out[0]));
    four_to_one_mux mux_1(.in({q[7], q[5], q[3], q[1]}), .sel(q2), .out(out[1]));

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
module four_bit_LZE (
    input wire [3:0] x,
    output reg [1:0] q
);

assign q[1] = x[3] &  x[2];
assign q[0] = (x[3] & ~x[2]) | (x[3] & x[2] & x[1] & ~x[0]) | &x;

endmodule
/* verilator lint_on UNUSEDSIGNAL */

module four_to_one_mux (
    input wire [3:0] in,
    input wire [1:0] sel,
    output reg out
);

always @(*) begin
    case (sel)
        2'b00: out = in[3];
        2'b01: out = in[2];
        2'b10: out = in[1];
        2'b11: out = in[0];
    endcase
end

endmodule
