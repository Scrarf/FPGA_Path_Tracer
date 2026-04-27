`include "src/arithmetic_cores/definitions.vh"
/*
rst, valid amd a valid flt in
*/

module bounds (
	input clk,
	input rst,
	input valid,
	input p_float3 flt,
	output wire p_float3 min,
	output wire p_float3 max
);

wire b_gt_x;
wire b_lt_x;

wire b_gt_y;
wire b_lt_y;

wire b_gt_z;
wire b_lt_z;

greater_than gt_x(.a(flt.x), .b(max.x), .result(b_gt_x));
less_than lt_x(.a(flt.x), .b(min.x), .result(b_lt_x));

greater_than gt_y(.a(flt.y), .b(max.y), .result(b_gt_y));
less_than lt_y(.a(flt.y), .b(min.y), .result(b_lt_y));

greater_than gt_z(.a(flt.z), .b(max.z), .result(b_gt_z));
less_than lt_z(.a(flt.z), .b(min.z), .result(b_lt_z));


always @(posedge clk) begin
	if (valid) begin
		if (rst) begin
			min <= flt;
			max <= flt;
		end else begin
			min.x <= b_lt_x ? flt.x : min.x;
			min.y <= b_lt_y ? flt.y : min.y;
			min.z <= b_lt_z ? flt.z : min.z;
			max.x <= b_gt_x ? flt.x : max.x;
			max.y <= b_gt_y ? flt.y : max.y;
			max.z <= b_gt_z ? flt.z : max.z;
		end

	end
end

endmodule
