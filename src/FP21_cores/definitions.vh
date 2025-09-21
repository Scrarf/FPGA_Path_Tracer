`ifndef DEFINITIONS_VH
`define DEFINITIONS_VH


`define frac 12
`define exp 8


typedef struct packed{
	logic sign;
	logic [`exp:0] exp; //removed "signed" here remember just in case.
	logic [`frac:0] frac;
} u_float; //unpacked float


`endif
