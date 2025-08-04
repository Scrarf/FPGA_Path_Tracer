// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VFP21_mult__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

VFP21_mult::VFP21_mult(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VFP21_mult__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , sign_a{vlSymsp->TOP.sign_a}
    , sign_b{vlSymsp->TOP.sign_b}
    , sign_c_out{vlSymsp->TOP.sign_c_out}
    , frac_a{vlSymsp->TOP.frac_a}
    , frac_b{vlSymsp->TOP.frac_b}
    , exp_a{vlSymsp->TOP.exp_a}
    , exp_b{vlSymsp->TOP.exp_b}
    , frac_c_out{vlSymsp->TOP.frac_c_out}
    , exp_c_out{vlSymsp->TOP.exp_c_out}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

VFP21_mult::VFP21_mult(const char* _vcname__)
    : VFP21_mult(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VFP21_mult::~VFP21_mult() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VFP21_mult___024root___eval_debug_assertions(VFP21_mult___024root* vlSelf);
#endif  // VL_DEBUG
void VFP21_mult___024root___eval_static(VFP21_mult___024root* vlSelf);
void VFP21_mult___024root___eval_initial(VFP21_mult___024root* vlSelf);
void VFP21_mult___024root___eval_settle(VFP21_mult___024root* vlSelf);
void VFP21_mult___024root___eval(VFP21_mult___024root* vlSelf);

void VFP21_mult::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VFP21_mult::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VFP21_mult___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VFP21_mult___024root___eval_static(&(vlSymsp->TOP));
        VFP21_mult___024root___eval_initial(&(vlSymsp->TOP));
        VFP21_mult___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VFP21_mult___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VFP21_mult::eventsPending() { return false; }

uint64_t VFP21_mult::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VFP21_mult::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VFP21_mult___024root___eval_final(VFP21_mult___024root* vlSelf);

VL_ATTR_COLD void VFP21_mult::final() {
    VFP21_mult___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VFP21_mult::hierName() const { return vlSymsp->name(); }
const char* VFP21_mult::modelName() const { return "VFP21_mult"; }
unsigned VFP21_mult::threads() const { return 1; }
void VFP21_mult::prepareClone() const { contextp()->prepareClone(); }
void VFP21_mult::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> VFP21_mult::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void VFP21_mult___024root__trace_decl_types(VerilatedVcd* tracep);

void VFP21_mult___024root__trace_init_top(VFP21_mult___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VFP21_mult___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VFP21_mult___024root*>(voidSelf);
    VFP21_mult__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    VFP21_mult___024root__trace_decl_types(tracep);
    VFP21_mult___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void VFP21_mult___024root__trace_register(VFP21_mult___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VFP21_mult::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'VFP21_mult::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    VFP21_mult___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
