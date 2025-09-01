/*
Asynchronous FIFO with the word size of 36 bits and depth of 512.
WORK IN PROGRESS
*/

//following https://mohammedsahil.weebly.com/uploads/1/2/8/5/12851579/fifo_report.pdf

// NOT YET VERIFIED!!!
module fifo_36bit_sync_ecp5 (
    input clk,
    input rst,

    input [35:0] wr_data,
    input wr_en,
    output full,

    output [35:0] rd_data,
    input rd_en,
    output empty
);

reg [9:0] wr_ptr;
reg [9:0] rd_ptr;

reg [35:0] memory [0:511];

wire equal = (wr_ptr[8:0] == rd_ptr[8:0]);

assign empty = equal && (wr_ptr[9] == rd_ptr[9]);
assign full = equal && (wr_ptr[9] != rd_ptr[9]);


always @(posedge clk) begin
	if (wr_en && !full) memory[wr_ptr[8:0]] <= wr_data; 
	rd_data <= memory[rd_ptr[8:0]];
end

always @(posedge clk or posedge rst) begin
	if (rst) begin
		wr_ptr <= 0;
		rd_ptr <= 0;
	end else begin
		if (wr_en && !full) wr_ptr <= wr_ptr + 1'b1;
		if (rd_en && !empty) rd_ptr <= rd_ptr + 1'b1;
	end
end

endmodule
