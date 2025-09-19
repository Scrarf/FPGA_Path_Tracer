/*
Asynchronous FIFO with the word size of 36 bits and depth of 512.
WORK IN PROGRESS
*/

//following https://mohammedsahil.weebly.com/uploads/1/2/8/5/12851579/fifo_report.pdf

// NOT YET VERIFIED!!!
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
		if (wr_en && !full) wr_ptr <= wr_ptr + 1;
		if (rd_en && !empty) rd_ptr <= rd_ptr + 1;
	end
end

endmodule


/*
NEXTPNR REPORT:

Max frequency: 240.85 MHz.

Info: Device utilisation:
Info:             TRELLIS_IO:      78/    365    21%
Info:                   DCCA:       1/     56     1%
Info:                 DP16KD:       1/    208     0%
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
Info:             TRELLIS_FF:     103/  83640     0%
Info:           TRELLIS_COMB:      89/  83640     0%
Info:           TRELLIS_RAMW:       0/  10455     0%
*/