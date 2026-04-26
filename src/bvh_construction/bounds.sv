`include "src/arithmetic_cores/definitions.vh"


module bounds (
	input clk,
	input rst,
	input valid,
	input p_float3 flt,
	output p_float3 min,
	output p_float3 max
);

wire b_gt_x;
wire b_lt_x;

wire b_gt_y;
wire b_lt_y;

wire b_gt_z;
wire b_lt_z;

p_float3 flt_d;

greater_than gt_x(.clk(clk), .a(flt.x), .b(max.x), .result(b_gt_x));
less_than lt_x(.clk(clk), .a(flt.x), .b(min.x), .result(b_lt_x));

greater_than gt_y(.clk(clk), .a(flt.y), .b(max.y), .result(b_gt_y));
less_than lt_y(.clk(clk), .a(flt.y), .b(min.y), .result(b_lt_y));

greater_than gt_z(.clk(clk), .a(flt.z), .b(max.z), .result(b_gt_z));
less_than lt_z(.clk(clk), .a(flt.z), .b(min.z), .result(b_lt_z));

reg first;
reg valid_d;
reg first_d;

always @(posedge clk) begin

	if (rst) begin
		first <= 1'b1;
	end else begin


		flt_d <= flt;
		valid_d <= valid;
		first_d <= first;
		if (first && valid) first <= 1'b0;
		//$display("t=%0t first=%b valid_d=%b b_gt_z=%b b_lt_z=%b flt_d.z=%b min.z=%b max.z=%b",
		//$time, first, valid_d, b_gt_z, b_lt_z, flt_d.z, min.z, max.z);

		if (valid_d) begin
			if (first_d) begin
				min <= flt;
				max <= flt;
				
				first <= 1'b0;
			end else begin
				min.x <= b_lt_x ? flt_d.x : min.x;
				min.y <= b_lt_y ? flt_d.y : min.y;
				min.z <= b_lt_z ? flt_d.z : min.z;
				
				max.x <= b_gt_x ? flt_d.x : max.x;
				max.y <= b_gt_y ? flt_d.y : max.y;
				max.z <= b_gt_z ? flt_d.z : max.z;
			end
		end
	end
end

endmodule
