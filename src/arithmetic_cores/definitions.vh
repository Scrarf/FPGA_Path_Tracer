`ifndef DEFINITIONS_VH
`define DEFINITIONS_VH


`define frac 12
`define exp 8


typedef struct packed{
	logic sign;
	logic [`exp:0] exp;
	logic [`frac:0] frac;
} p_float; //unpacked float


`endif
