

/*
instruction template:
	<instruction> <dst> <src1> <src2>
*/

module core (
	(* dont_touch *)input clk,
	(* dont_touch *)input rst,
	output reg debug_led //this is just to force yosys to not optimize everything.
);

(* dont_touch *) reg [31:0] r [7:0]/* verilator public_flat_rw */;


(* dont_touch *) reg [31:0] IMEM [255:0]/* verilator public_flat_rw */;

parameter NOP = 8'h00;
parameter MOV = 8'h01;
parameter NOT = 8'h02;
parameter AND = 8'h03;
parameter OR = 8'h04;
parameter XOR = 8'h05;

parameter SL = 8'h06;
parameter SR = 8'h07;

parameter ADD = 8'h08;
parameter SUB = 8'h09;

(* dont_touch *) reg [31:0] ins;


always @(posedge clk) begin
	if (rst) begin
		r[7] <= 0;
	end else begin
		r[7] <= r[7] + 1;
		
		ins <= IMEM[r[7]][31:0];
		
		case (ins[31:24])
		NOP:;
		MOV: r[ins[18:16]] <= {24'b0, ins[15:8]};
		NOT: r[ins[18:16]] <= ~r[ins[10:8]];
		AND: r[ins[18:16]] <= r[ins[10:8]] & r[ins[2:0]];
		OR: r[ins[18:16]] <= r[ins[10:8]] | r[ins[2:0]];
		XOR: r[ins[18:16]] <= r[ins[10:8]] ^ r[ins[2:0]];
		SL: r[ins[18:16]] <= r[ins[10:8]] << r[ins[2:0]];
		SR: r[ins[18:16]] <= r[ins[10:8]] >> r[ins[2:0]];
		ADD: r[ins[18:16]] <= r[ins[10:8]] + r[ins[2:0]];
		SUB: r[ins[18:16]] <= r[ins[10:8]] - r[ins[2:0]];
		default:;
		endcase	
	end
	debug_led <= ^r[7]; 
end
endmodule
