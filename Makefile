#design is planned to be tested on Lattice LFE5U-85F-7BG381I.

FREQ = 100 #MHz
PACKAGE = CABGA381
SPEED_GRADE = 7

TIMING_DIR = logs/timing/
YOSYS_JSON_DIR = yosys_json/
SIM_SKELETON_DIR = src/sim_cpp/verilator_skeleton/verilator_skeleton.cpp 
VERILOG_DEPENDENCY_DIR = -y src/arithmetic_cores \
						 -y src/fifo \
						 -y src/ray_triangle_intersection/vector_operations +libext+.sv

clean:
	rm -f *.vvp *.vcd *.json


verilate_mult:
	verilator -Wall --trace --exe  --build -cc $(VERILOG_DEPENDENCY_DIR) \
	src/sim_cpp/sim_mult.cpp $(SIM_SKELETON_DIR) \
	src/arithmetic_cores/mult.sv \
	src/arithmetic_cores/definitions.vh \
	-top-module mult
	obj_dir/Vmult
yosys_mult:
	yosys -p 'synth_ecp5 -json $(YOSYS_JSON_DIR)yosys_mult.json' src/arithmetic_cores/_mult.sv
nextpnr_mult:
	nextpnr-ecp5 --85k --package $(PACKAGE) --speed $(SPEED_GRADE) \
	--json $(YOSYS_JSON_DIR)yosys_mult.json \
	--freq $(FREQ) 2>&1 | tee $(TIMING_DIR)nextpnr_mult.log



verilate_add:
	verilator -Wall --trace --exe --build -cc $(VERILOG_DEPENDENCY_DIR) \
	src/sim_cpp/sim_add.cpp $(SIM_SKELETON_DIR)\
	src/arithmetic_cores/add.sv \
	src/arithmetic_cores/definitions.vh \
	--top-module add
	obj_dir/Vadd
gtkwave_add:
	gtkwave logs/vcd/add.vcd gtkwave_saves/add.gtkw
yosys_add:
	yosys -p 'synth_ecp5 -json $(YOSYS_JSON_DIR)yosys_add.json' src/arithmetic_cores/add.sv src/arithmetic_cores/sixteen_bit_lzc.sv
nextpnr_add:
	nextpnr-ecp5 --85k --package $(PACKAGE) --speed $(SPEED_GRADE) \
	--json $(YOSYS_JSON_DIR)yosys_add.json \
	--freq $(FREQ) 2>&1 | tee $(TIMING_DIR)nextpnr_add.log



verilate_pack: #not tested
	verilator -Wall --trace --exe --build -cc src/sim_cpp/sim_pack.cpp src/arithmetic_cores/pack.sv
	obj_dir/Vpack



verilate_greater_than: #tested but gives error_rate: 0.002248% due to precision errors.
	verilator -Wall --trace --exe --build -cc $(VERILOG_DEPENDENCY_DIR) \
	src/sim_cpp/sim_greater_than.cpp $(SIM_SKELETON_DIR)\
	src/arithmetic_cores/greater_than.sv
	obj_dir/Vgreater_than
yosys_greater_than:
	yosys -p 'synth_ecp5 -json $(YOSYS_JSON_DIR)yosys_greater_than.json' src/arithmetic_cores/greater_than.sv
nextpnr_greater_than:
	nextpnr-ecp5 --85k --package $(PACKAGE) --speed $(SPEED_GRADE) \
	--json $(YOSYS_JSON_DIR)yosys_greater_than.json \
	--freq $(FREQ) 2>&1 | tee $(TIMING_DIR)nextpnr_greater_than.log



verilate_less_than: #tested but gives error_rate: 0.002265% due to precision errors.
	verilator -Wall --trace --exe --build -cc $(VERILOG_DEPENDENCY_DIR) \
	src/sim_cpp/sim_less_than.cpp $(SIM_SKELETON_DIR)\
	src/arithmetic_cores/less_than.sv
	obj_dir/Vless_than
yosys_less_than:
	yosys -p 'synth_ecp5 -json $(YOSYS_JSON_DIR)yosys_less_than.json' src/arithmetic_cores/less_than.sv
nextpnr_less_than:
	nextpnr-ecp5 --85k --package $(PACKAGE) --speed $(SPEED_GRADE) \
	--json $(YOSYS_JSON_DIR)yosys_less_than.json \
	--freq $(FREQ) 2>&1 | tee $(TIMING_DIR)nextpnr_less_than.log



verilate_sixteen_bit_LZC:
	verilator -Wall --trace --exe --build -cc src/sim_cpp/sim_sixteen_bit_LZC.cpp src/arithmetic_cores/sixteen_bit_lzc.sv
	obj_dir/Vsixteen_bit_lzc



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

