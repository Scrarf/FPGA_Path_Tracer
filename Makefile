
compile:
	yosys -p 'synth_ecp5 -json top.json' ray_triangle.v

clean:
	rm -f *.vvp *.vcd *.json


# tested and mostly works but sometimes returns very high number.
# it could either be a verilog logic bug, overflow or cpp testbench bug.
verilate_FP21_mult:
	verilator -Wall --trace `# --public-params` `# --public-flat-rw` --cc FP21_cores/FP21_mult.v
	verilator -Wall --trace `# --coverage ``# --vcd `--exe `# --public-flat-rw` `# --public-params` --build -cc sim_cpp/sim_mult.cpp FP21_cores/FP21_mult.v FP21_cores/definitions.vh
	obj_dir/VFP21_mult
	`# gtkwave top_result.vcd`
yosys_FP21_mult:
	yosys -p 'synth_ecp5 -json json/FP21_mult.json' FP21_cores/FP21_mult.v

nextpnr_FP21_mult:
	nextpnr-ecp5 --85k --package CABGA381 --speed 7 --json FP21_mult.json


verilate_FP21_pack: #not tested
	verilator -Wall --trace --cc FP21_cores/FP21_pack.v
	verilator -Wall --trace `# --coverage ``# --vcd `--exe --build -cc sim_cpp/sim_pack.cpp FP21_cores/FP21_pack.v
	obj_dir/VFP21_pack

verilate_FP21_greater_than: #tested but gives error_rate: 0.002248% due to precision errors.
	verilator -Wall --trace --cc FP21_cores/FP21_greater_than.v
	verilator -Wall --trace `# --coverage ``# --vcd `--exe --build -cc sim_cpp/sim_greater_than.cpp FP21_cores/FP21_greater_than.v
	obj_dir/VFP21_greater_than

verilate_FP21_less_than: #tested but gives error_rate: 0.002265% die to precision errors.
	verilator -Wall --trace --cc FP21_cores/FP21_less_than.v
	verilator -Wall --trace `# --coverage ``# --vcd `--exe --build -cc sim_cpp/sim_less_than.cpp FP21_cores/FP21_less_than.v
	obj_dir/VFP21_less_than


#extpnr-ecp5 --json  --85k FP21_cores/FP21_mult.v 
