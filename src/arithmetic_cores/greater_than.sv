`include "src/arithmetic_cores/definitions.vh"

module greater_than (
	input p_float a,
	input p_float b,
	
	output wire result
);


//combinatorial logic

assign result = ((a.sign ^ b.sign) ? b.sign :
				 (($signed(a.exp) > $signed(b.exp)) ? 1'b1 :
				 ((a.frac > b.frac) & ($signed(a.exp) == $signed(b.exp)))) ^ (a.sign & b.sign));


endmodule

