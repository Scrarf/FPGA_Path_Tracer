// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VFP21_greater_than__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

VFP21_greater_than::VFP21_greater_than(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VFP21_greater_than__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , sign_a{vlSymsp->TOP.sign_a}
    , sign_b{vlSymsp->TOP.sign_b}
    , result{vlSymsp->TOP.result}
    , exp_a{vlSymsp->TOP.exp_a}
    , frac_a{vlSymsp->TOP.frac_a}
    , exp_b{vlSymsp->TOP.exp_b}
    , frac_b{vlSymsp->TOP.frac_b}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

VFP21_greater_than::VFP21_greater_than(const char* _vcname__)
    : VFP21_greater_than(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VFP21_greater_than::~VFP21_greater_than() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VFP21_greater_than___024root___eval_debug_assertions(VFP21_greater_than___024root* vlSelf);
#endif  // VL_DEBUG
void VFP21_greater_than___024root___eval_static(VFP21_greater_than___024root* vlSelf);
void VFP21_greater_than___024root___eval_initial(VFP21_greater_than___024root* vlSelf);
void VFP21_greater_than___024root___eval_settle(VFP21_greater_than___024root* vlSelf);
void VFP21_greater_than___024root___eval(VFP21_greater_than___024root* vlSelf);

void VFP21_greater_than::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VFP21_greater_than::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VFP21_greater_than___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VFP21_greater_than___024root___eval_static(&(vlSymsp->TOP));
        VFP21_greater_than___024root___eval_initial(&(vlSymsp->TOP));
        VFP21_greater_than___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VFP21_greater_than___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VFP21_greater_than::eventsPending() { return false; }

uint64_t VFP21_greater_than::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VFP21_greater_than::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VFP21_greater_than___024root___eval_final(VFP21_greater_than___024root* vlSelf);

VL_ATTR_COLD void VFP21_greater_than::final() {
    VFP21_greater_than___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VFP21_greater_than::hierName() const { return vlSymsp->name(); }
const char* VFP21_greater_than::modelName() const { return "VFP21_greater_than"; }
unsigned VFP21_greater_than::threads() const { return 1; }
void VFP21_greater_than::prepareClone() const { contextp()->prepareClone(); }
void VFP21_greater_than::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> VFP21_greater_than::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void VFP21_greater_than___024root__trace_decl_types(VerilatedVcd* tracep);

void VFP21_greater_than___024root__trace_init_top(VFP21_greater_than___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VFP21_greater_than___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VFP21_greater_than___024root*>(voidSelf);
    VFP21_greater_than__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    VFP21_greater_than___024root__trace_decl_types(tracep);
    VFP21_greater_than___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void VFP21_greater_than___024root__trace_register(VFP21_greater_than___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VFP21_greater_than::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'VFP21_greater_than::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    VFP21_greater_than___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
