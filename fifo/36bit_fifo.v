/*
FIFO with the word size of 36 bits and depth of 512.
*/

module 36bit_fifo (
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

DP16KD #(
    .DATA_WIDTH_A(36),     // Port A width
    .DATA_WIDTH_B(36),     // Port B width
    .WRITEMODE_A("NORMAL"),// or "WRITETHROUGH", "READBEFOREWRITE"
    .WRITEMODE_B("NORMAL"),
    .CSDECODE_A(3'b000),   // Active CS decode
    .CSDECODE_B(3'b000)
) bram0 (
    // Port A (write)
    .DIA    (din[35:0]),    // Data in
    .DIPA   (4'b0),         // Parity bits in (optional)
    .ADA    (addr_a),       // Address
    .CEA    (1'b1),         // Chip enable
    .OCEA   (1'b0),         // Output reg enable
    .CLKA   (clk_a),        // Clock
    .WEA    (we_a),         // Write enable
    .CSA    (3'b000),       // CS lines

    // Port B (read)
    .DOB    (dout[35:0]),   // Data out
    .DOPB   (),             // Parity out (optional)
    .ADB    (addr_b),
    .CEB    (1'b1),
    .OCEB   (1'b1),
    .CLKB   (clk_b),
    .WEB    (1'b0),
    .CSB    (3'b000)
);


assign size = (rw_ptr - rd_ptr);

assign empty = (size == 0);
assign almost_empty = (size < 8);

assign full = (size == 511);
assign almost_full = (size > 493);

always @(posedge wr_clk) begin
	if (~full & wr_en) begin
		
		wr_ptr <= wr_ptr + 1;
	end
end

always @(posedge rd_clk) begin
	if (~empty & rd_en) begin
		
		rd_ptr <= rd_ptr + 1;
	end


end

always @(posedge rst) begin
	wr_ptr <= 0;
	rd_ptr <= 0;
end

endmodule


