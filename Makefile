clean:
	rm -f *.vvp *.vcd *.json


verilate_FP21_mult:
	verilator -Wall --trace --cc src/FP21_cores/FP21_mult.v
	verilator -Wall --trace --exe `# --public-params` --build -cc src/sim_cpp/sim_mult.cpp src/FP21_cores/FP21_mult.v src/FP21_cores/definitions.vh
	obj_dir/VFP21_mult
yosys_FP21_mult:
	yosys -p 'synth_ecp5 -json yosys_json/yosys_FP21_mult.json' src/FP21_cores/FP21_mult.v
nextpnr_FP21_mult:
	nextpnr-ecp5 --85k --package CABGA381 --speed 7 \
	--json yosys_json/yosys_FP21_mult.json \
	--freq 48  2>&1 | tee logs/timing/nextpnr_FP21_mult.log





verilate_FP21_pack: #not tested
	verilator -Wall --trace --cc src/FP21_cores/FP21_pack.v
	verilator -Wall --trace --exe --build -cc src/sim_cpp/sim_pack.cpp src/FP21_cores/FP21_pack.v
	obj_dir/VFP21_pack



verilate_FP21_greater_than: #tested but gives error_rate: 0.002248% due to precision errors.
	verilator -Wall --trace --cc src/FP21_cores/FP21_greater_than.v
	verilator -Wall --trace --exe --build -cc src/sim_cpp/sim_greater_than.cpp src/FP21_cores/FP21_greater_than.v
	obj_dir/VFP21_greater_than
yosys_FP21_greater_than:
	yosys -p 'synth_ecp5 -json yosys_json/yosys_FP21_greater_than.json' src/FP21_cores/FP21_greater_than.v
nextpnr_FP21_greater_than:
	nextpnr-ecp5 --85k --package CABGA381 --speed 7 \
	--json yosys_json/yosys_FP21_greater_than.json \
	--freq 48 2>&1 | tee logs/timing/nextpnr_FP21_greater_than.log



verilate_FP21_less_than: #tested but gives error_rate: 0.002265% die to precision errors.
	verilator -Wall --trace --cc src/FP21_cores/FP21_less_than.v
	verilator -Wall --trace --exe --build -cc src/sim_cpp/sim_less_than.cpp src/FP21_cores/FP21_less_than.v
	obj_dir/VFP21_less_than
yosys_FP21_less_than:
	yosys -p 'synth_ecp5 -json yosys_json/yosys_FP21_less_than.json' src/FP21_cores/FP21_less_than.v
nextpnr_FP21_less_than:
	nextpnr-ecp5 --85k --package CABGA381 --speed 7 \
	--json yosys_json/yosys_FP21_less_than.json \
	--freq 48 2>&1 | tee logs/timing/nextpnr_FP21_less_than.log



verilate_sixteen_bit_LZC:
	verilator -Wall --trace --cc src/FP21_cores/sixteen_bit_LZC.v
	verilator -Wall --trace --exe --build -cc src/sim_cpp/sim_sixteen_bit_LZC.cpp src/FP21_cores/sixteen_bit_LZC.v
	obj_dir/Vsixteen_bit_LZC




verilate_FP21_add:
	verilator -Wall --trace --cc src/FP21_cores/FP21_add.v src/FP21_cores/sixteen_bit_LZC.v
	verilator -Wall --trace --exe`# --public-params` --build -cc --top-module FP21_add \
	src/sim_cpp/sim_add.cpp src/FP21_cores/FP21_add.v src/FP21_cores/sixteen_bit_LZC.v src/FP21_cores/definitions.vh
	obj_dir/VFP21_add
gtkwave_FP21_add:
	gtkwave logs/vcd/FP21_add.vcd gtkwave_saves/FP21_add.gtkw
yosys_FP21_add:
	yosys -p 'synth_ecp5 -json yosys_json/yosys_FP21_add.json' src/FP21_cores/FP21_add.v src/FP21_cores/sixteen_bit_LZC.v
nextpnr_FP21_add:
	nextpnr-ecp5 --85k --package CABGA381 --speed 7 --detailed-timing-report \
	--json yosys_json/yosys_FP21_add.json \
	--freq 48 2>&1 | tee logs/timing/nextpnr_FP21_add.log