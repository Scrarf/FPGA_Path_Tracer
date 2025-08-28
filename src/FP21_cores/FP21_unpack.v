`include "FP21_cores/definitions.vh"

//needs to add support for denormalized FP values (if exp = -126, then leading frac bit = 0)

module FP21_unpack(
    FP21_in,

    sign,
    exp,
    frac
    );

input [`frac + `exp:0] FP21_in;
output sign;
output [`exp:0] exp;
output [`frac:0] frac;

assign sign = FP21_in[`frac + `exp];
assign exp = {1'b0, FP21_in[(`frac + `exp - 1):`frac]} - 127;
assign frac[`frac:0] = {1'b1, FP21_in[(`frac-1):0]};

endmodule
