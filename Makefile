#design is planned to be tested on Lattice LFE5U-85F-7BG381I.

FREQ = 100 #MHz
PACKAGE = CABGA381
SPEED_GRADE = 7

TIMING_DIR = logs/timing/
YOSYS_JSON_DIR = yosys_json/
SIM_SKELETON_DIR = src/sim_cpp/verilator_skeleton/verilator_skeleton.cpp 
VERILOG_DEPENDENCY_DIR = -y src/FP21_cores \
						 -y src/fifo \
						 -y src/ray_triangle_intersection/vector_operations +libext+.v

clean:
	rm -f *.vvp *.vcd *.json


verilate_FP21_mult:
	verilator -Wall --trace --exe  --build -cc $(VERILOG_DEPENDENCY_DIR) \
	src/sim_cpp/sim_mult.cpp $(SIM_SKELETON_DIR) \
	src/FP21_cores/FP21_mult.v \
	src/FP21_cores/definitions.vh \
	-top-module FP21_mult
	obj_dir/VFP21_mult
yosys_FP21_mult:
	yosys -p 'synth_ecp5 -json $(YOSYS_JSON_DIR)yosys_FP21_mult.json' src/FP21_cores/FP21_mult.v
nextpnr_FP21_mult:
	nextpnr-ecp5 --85k --package $(PACKAGE) --speed $(SPEED_GRADE) \
	--json $(YOSYS_JSON_DIR)yosys_FP21_mult.json \
	--freq $(FREQ) 2>&1 | tee $(TIMING_DIR)nextpnr_FP21_mult.log



verilate_add:
	verilator -Wall --trace --exe --build -cc $(VERILOG_DEPENDENCY_DIR) \
	src/sim_cpp/sim_add.cpp $(SIM_SKELETON_DIR)\
	src/FP21_cores/add.sv \
	src/FP21_cores/definitions.vh \
	--top-module add
	obj_dir/Vadd
gtkwave_FP21_add:
	gtkwave logs/vcd/add.vcd gtkwave_saves/add.gtkw
yosys_FP21_add:
	yosys -p 'synth_ecp5 -json $(YOSYS_JSON_DIR)yosys_FP21_add.json' src/FP21_cores/FP21_add.v src/FP21_cores/sixteen_bit_LZC.v
nextpnr_FP21_add:
	nextpnr-ecp5 --85k --package $(PACKAGE) --speed $(SPEED_GRADE) \
	--json $(YOSYS_JSON_DIR)yosys_FP21_add.json \
	--freq $(FREQ) 2>&1 | tee $(TIMING_DIR)nextpnr_FP21_add.log



verilate_FP21_pack: #not tested
	verilator -Wall --trace --exe --build -cc src/sim_cpp/sim_pack.cpp src/FP21_cores/FP21_pack.v
	obj_dir/VFP21_pack



verilate_FP21_greater_than: #tested but gives error_rate: 0.002248% due to precision errors.
	verilator -Wall --trace --exe --build -cc $(VERILOG_DEPENDENCY_DIR) \
	src/sim_cpp/sim_greater_than.cpp $(SIM_SKELETON_DIR)\
	src/FP21_cores/FP21_greater_than.v
	obj_dir/VFP21_greater_than
yosys_FP21_greater_than:
	yosys -p 'synth_ecp5 -json $(YOSYS_JSON_DIR)yosys_FP21_greater_than.json' src/FP21_cores/FP21_greater_than.v
nextpnr_FP21_greater_than:
	nextpnr-ecp5 --85k --package $(PACKAGE) --speed $(SPEED_GRADE) \
	--json $(YOSYS_JSON_DIR)yosys_FP21_greater_than.json \
	--freq $(FREQ) 2>&1 | tee $(TIMING_DIR)nextpnr_FP21_greater_than.log



verilate_FP21_less_than: #tested but gives error_rate: 0.002265% due to precision errors.
	verilator -Wall --trace --exe --build -cc $(VERILOG_DEPENDENCY_DIR) \
	src/sim_cpp/sim_less_than.cpp $(SIM_SKELETON_DIR)\
	src/FP21_cores/FP21_less_than.v
	obj_dir/VFP21_less_than
yosys_FP21_less_than:
	yosys -p 'synth_ecp5 -json $(YOSYS_JSON_DIR)yosys_FP21_less_than.json' src/FP21_cores/FP21_less_than.v
nextpnr_FP21_less_than:
	nextpnr-ecp5 --85k --package $(PACKAGE) --speed $(SPEED_GRADE) \
	--json $(YOSYS_JSON_DIR)yosys_FP21_less_than.json \
	--freq $(FREQ) 2>&1 | tee $(TIMING_DIR)nextpnr_FP21_less_than.log



verilate_sixteen_bit_LZC:
	verilator -Wall --trace --exe --build -cc src/sim_cpp/sim_sixteen_bit_LZC.cpp src/FP21_cores/sixteen_bit_LZC.v
	obj_dir/Vsixteen_bit_LZC



verilate_fifo_36bit_sync:
	verilator -Wall --trace --exe --build -cc \
	src/sim_cpp/sim_fifo_36bit_sync.cpp src/fifo/fifo_36bit_sync.v
	obj_dir/Vfifo_36bit_sync
yosys_fifo_36bit_sync:
	yosys -p 'synth_ecp5 -json $(YOSYS_JSON_DIR)yosys_fifo_36bit_sync.json' src/fifo/fifo_36bit_sync.v
nextpnr_fifo_36bit_sync:
	nextpnr-ecp5 --85k --package $(PACKAGE) --speed $(SPEED_GRADE) \
	--json $(YOSYS_JSON_DIR)yosys_fifo_36bit_sync.json \
	--freq $(FREQ) 2>&1 | tee $(TIMING_DIR)nextpnr_fifo_36bit_sync.log


verilate_cross_product_component:
	verilator -Wall --trace --exe --build -cc $(VERILOG_DEPENDENCY_DIR) \
	src/sim_cpp/cross_product_component.cpp $(SIM_SKELETON_DIR) \
	src/ray_triangle_intersection/vector_operations/cross_product_component.v
	obj_dir/Vcross_product_component


verilate_cross_product:
	verilator -Wall --trace --exe --build -cc $(VERILOG_DEPENDENCY_DIR) \
	src/sim_cpp/cross_product.cpp $(SIM_SKELETON_DIR)\
	src/ray_triangle_intersection/vector_operations/cross_product.v \
	--top-module cross_product
	obj_dir/Vcross_product

