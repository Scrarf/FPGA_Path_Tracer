/*
Asynchronous FIFO with the word size of 36 bits and depth of 512.
WORK IN PROGRESS
*/

//following https://mohammedsahil.weebly.com/uploads/1/2/8/5/12851579/fifo_report.pdf

module fifo_36bit_sync (
	input clk,
	input rst,

	input [35:0] wr_data,
	input wr_en,
	output full,

	output [35:0] rd_data,
	input rd_en,
	output empty
);

reg [9:0] rd_ptr, wr_ptr;

reg [35:0] memory [511:0];

wire equals = (wr_ptr[8:0] == rd_ptr[8:0]);

assign empty = equals & (wr_ptr[9] == rd_ptr[9]);
assign full = equals & (wr_ptr[9] != rd_ptr[9]);

assign rd_data = memory[rd_ptr[8:0]];

always @(posedge clk or posedge rst) begin
	if(rst) begin
		rd_ptr <= 0;
		wr_ptr <= 0;
	end else begin

		wr_ptr <= wr_ptr + wr_en;
		rd_ptr <= rd_ptr + rd_en;

		if (wr_en) memory[wr_ptr[8:0]] <= wr_data;
	end
end

endmodule