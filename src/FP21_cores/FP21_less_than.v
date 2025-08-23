`include "src/FP21_cores/definitions.vh"

/*
Tested but gives error_rate: 0.0022% due to precision errors.
Works with both packed and unpacked FP21s.
*/

module FP21_less_than (
	clk,

	sign_a,
	exp_a,
	frac_a,
	sign_b,
	exp_b,
	frac_b,
	result
);

input wire clk;

input wire sign_a;
input wire signed [`exp:0] exp_a;
input wire [`frac:0] frac_a;

input wire sign_b;
input wire signed [`exp:0] exp_b;
input wire [`frac:0] frac_b;

output reg result;

/*
Note: actually now this one takes less
hardware than greater_than.
*/

//1 pipeline stage
always @(posedge clk) begin
	result <= ((sign_a ^ sign_b) ? sign_a :
		 	  ((exp_a < exp_b) ? 1'b1 :
		 	  ((frac_a < frac_b) & (exp_a == exp_b))) ^ (sign_a & sign_b));
end

endmodule


/*
NEXTPNR REPORT:

No f(max) available

Info: Device utilisation:
Info:             TRELLIS_IO:      48/    365    13%
Info:                   DCCA:       0/     56     0%
Info:                 DP16KD:       0/    208     0%
Info:             MULT18X18D:       0/    156     0%
Info:                 ALU54B:       0/     78     0%
Info:                EHXPLLL:       0/      4     0%
Info:                EXTREFB:       0/      2     0%
Info:                   DCUA:       0/      2     0%
Info:              PCSCLKDIV:       0/      2     0%
Info:                IOLOGIC:       0/    224     0%
Info:               SIOLOGIC:       0/    141     0%
Info:                    GSR:       0/      1     0%
Info:                  JTAGG:       0/      1     0%
Info:                   OSCG:       0/      1     0%
Info:                  SEDGA:       0/      1     0%
Info:                    DTR:       0/      1     0%
Info:                USRMCLK:       0/      1     0%
Info:                CLKDIVF:       0/      4     0%
Info:              ECLKSYNCB:       0/     10     0%
Info:                DLLDELD:       0/      8     0%
Info:                 DDRDLL:       0/      4     0%
Info:                DQSBUFM:       0/     14     0%
Info:        TRELLIS_ECLKBUF:       0/      8     0%
Info:           ECLKBRIDGECS:       0/      2     0%
Info:                   DCSC:       0/      2     0%
Info:             TRELLIS_FF:       1/  83640     0%
Info:           TRELLIS_COMB:      45/  83640     0%
Info:           TRELLIS_RAMW:       0/  10455     0%

*/
