`include "FP21_cores/definitions.vh"

module FP21_pack(
    sign,
    exp,
    frac,

    FP21_out
    );

input sign;
input [`exp:0] exp;
input [`frac:0] frac;
output [`frac + `exp:0] FP21_out;

assign FP21_out[(`frac + `exp)] = sign;
assign FP21_out[(`frac + `exp - 1):`frac] = exp[(`exp - 1):0] + 127;
assign FP21_out[(`frac - 1):0] = frac[(`frac - 1):0];

endmodule
