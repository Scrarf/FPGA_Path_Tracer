#design is planned to be tested on Lattice LFE5U-85F-7BG381I.

freq = 100
package = CABGA381
speed_grade = 7

timing_dir = logs/timing/
yosys_json_dir = yosys_json/


clean:
	rm -f *.vvp *.vcd *.json


verilate_FP21_mult:
	verilator -Wall --trace --cc src/FP21_cores/FP21_mult.v
	verilator -Wall --trace --exe `# --public-params` --build -cc src/sim_cpp/sim_mult.cpp src/FP21_cores/FP21_mult.v src/FP21_cores/definitions.vh
	obj_dir/VFP21_mult
yosys_FP21_mult:
	yosys -p 'synth_ecp5 -json $(yosys_json_dir)yosys_FP21_mult.json' src/FP21_cores/FP21_mult.v
nextpnr_FP21_mult:
	nextpnr-ecp5 --85k --package $(package) --speed $(speed_grade) \
	--json $(yosys_json_dir)yosys_FP21_mult.json \
	--freq $(freq) 2>&1 | tee $(timing_dir)nextpnr_FP21_mult.log





verilate_FP21_pack: #not tested
	verilator -Wall --trace --cc src/FP21_cores/FP21_pack.v
	verilator -Wall --trace --exe --build -cc src/sim_cpp/sim_pack.cpp src/FP21_cores/FP21_pack.v
	obj_dir/VFP21_pack



verilate_FP21_greater_than: #tested but gives error_rate: 0.002248% due to precision errors.
	verilator -Wall --trace --cc src/FP21_cores/FP21_greater_than.v
	verilator -Wall --trace --exe --build -cc src/sim_cpp/sim_greater_than.cpp src/FP21_cores/FP21_greater_than.v
	obj_dir/VFP21_greater_than
yosys_FP21_greater_than:
	yosys -p 'synth_ecp5 -json $(yosys_json_dir)yosys_FP21_greater_than.json' src/FP21_cores/FP21_greater_than.v
nextpnr_FP21_greater_than:
	nextpnr-ecp5 --85k --package $(package) --speed $(speed_grade) \
	--json $(yosys_json_dir)yosys_FP21_greater_than.json \
	--freq $(freq) 2>&1 | tee $(timing_dir)nextpnr_FP21_greater_than.log



verilate_FP21_less_than: #tested but gives error_rate: 0.002265% due to precision errors.
	verilator -Wall --trace --cc src/FP21_cores/FP21_less_than.v
	verilator -Wall --trace --exe --build -cc src/sim_cpp/sim_less_than.cpp src/FP21_cores/FP21_less_than.v
	obj_dir/VFP21_less_than
yosys_FP21_less_than:
	yosys -p 'synth_ecp5 -json $(yosys_json_dir)yosys_FP21_less_than.json' src/FP21_cores/FP21_less_than.v
nextpnr_FP21_less_than:
	nextpnr-ecp5 --85k --package $(package) --speed $(speed_grade) \
	--json $(yosys_json_dir)yosys_FP21_less_than.json \
	--freq $(freq) 2>&1 | tee $(timing_dir)nextpnr_FP21_less_than.log



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
	yosys -p 'synth_ecp5 -json $(yosys_json_dir)yosys_FP21_add.json' src/FP21_cores/FP21_add.v src/FP21_cores/sixteen_bit_LZC.v
nextpnr_FP21_add:
	nextpnr-ecp5 --85k --package $(package) --speed $(speed_grade) `# --detailed-timing-report `\
	--json $(yosys_json_dir)yosys_FP21_add.json \
	--freq $(freq) 2>&1 | tee $(timing_dir)nextpnr_FP21_add.log

verilate_fifo_36bit_sync:
	verilator -Wall --trace --cc src/fifo/fifo_36bit_sync.v
	verilator -Wall --trace --exe --build -cc \
	src/sim_cpp/sim_fifo_36bit_sync.cpp src/fifo/fifo_36bit_sync.v
	obj_dir/Vfifo_36bit_sync
yosys_fifo_36bit_sync:
	yosys -p 'synth_ecp5 -json $(yosys_json_dir)yosys_fifo_36bit_sync.json' src/fifo/fifo_36bit_sync.v
nextpnr_fifo_36bit_sync:
	nextpnr-ecp5 --85k --package $(package) --speed $(speed_grade) \
	--json $(yosys_json_dir)yosys_fifo_36bit_sync.json \
	--freq $(freq) 2>&1 | tee $(timing_dir)nextpnr_fifo_36bit_sync.log
