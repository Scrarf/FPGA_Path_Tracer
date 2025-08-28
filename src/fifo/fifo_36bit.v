/*
FIFO with the word size of 36 bits and depth of 512.
WORK IN PROGRESS
*/

module fifo_36bit (
	wr_clk,
	wr_data,
	wr_en,
	full,
	almost_full,
	rd_clk,
	rd_data,
	rd_en,
	empty,
	almost_empty,
	size,
	rst
	
);

input wr_clk;
input rd_clk;
input wr_en;
input rd_en;

input [35:0] wr_data;
output [35:0] rd_data;

output empty;
output full;
output almost_empty;
output almost_full;

input rst;

reg [8:0] wr_ptr;
reg [8:0] rd_ptr;

reg [35:0] memory [511:0]


assign size = (rw_ptr - rd_ptr);

assign empty = (size == 0);
assign almost_empty = (size < 8);

assign full = (size == 511);
assign almost_full = (size > 493);

always @(posedge wr_clk) begin
	if (~full & wr_en) begin
		memory[wr_ptr] <= wr_data;
		
		wr_ptr <= wr_ptr + 1;
	end
end

always @(posedge rd_clk) begin
	if (~empty & rd_en) begin
		rd_data <= memory[rd_ptr];

		rd_ptr <= rd_ptr + 1;
	end
end

always @(posedge rst) begin
	wr_ptr <= 0;
	rd_ptr <= 0;
end

endmodule


