`ifndef DEFINITIONS_VH
`define DEFINITIONS_VH


`define frac 12
`define exp 8



typedef struct packed{
	logic sign;
	logic [`exp:0] exp;
	logic [`frac:0] frac;
} p_float;

typedef struct packed {
	p_float x;
	p_float y;
	p_float z;
} p_float3;


`define mult(base_name, in_a, in_b) \
	p_float base_name``_net; \
	mult base_name(.clk(clk), .a(in_a), .b(in_b), .c(base_name``_net));

`define add(base_name, in_a, in_b) \
	p_float base_name``_net; \
	add base_name(.clk(clk), .a(in_a), .b(in_b), .c(base_name``_net));

`define neg_p_float(net) \
	{~(net.sign), net.exp, net.frac}


`endif

