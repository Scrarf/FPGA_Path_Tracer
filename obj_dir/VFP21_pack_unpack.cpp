// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VFP21_pack_unpack__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

VFP21_pack_unpack::VFP21_pack_unpack(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VFP21_pack_unpack__Syms(contextp(), _vcname__, this)}
    , FP21_pack__02Esign{vlSymsp->TOP.FP21_pack__02Esign}
    , FP21_unpack__02Esign{vlSymsp->TOP.FP21_unpack__02Esign}
    , FP21_pack__02Eexp{vlSymsp->TOP.FP21_pack__02Eexp}
    , FP21_pack__02Efrac{vlSymsp->TOP.FP21_pack__02Efrac}
    , FP21_unpack__02Eexp{vlSymsp->TOP.FP21_unpack__02Eexp}
    , FP21_unpack__02Efrac{vlSymsp->TOP.FP21_unpack__02Efrac}
    , FP21_out{vlSymsp->TOP.FP21_out}
    , FP21_in{vlSymsp->TOP.FP21_in}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

VFP21_pack_unpack::VFP21_pack_unpack(const char* _vcname__)
    : VFP21_pack_unpack(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VFP21_pack_unpack::~VFP21_pack_unpack() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VFP21_pack_unpack___024root___eval_debug_assertions(VFP21_pack_unpack___024root* vlSelf);
#endif  // VL_DEBUG
void VFP21_pack_unpack___024root___eval_static(VFP21_pack_unpack___024root* vlSelf);
void VFP21_pack_unpack___024root___eval_initial(VFP21_pack_unpack___024root* vlSelf);
void VFP21_pack_unpack___024root___eval_settle(VFP21_pack_unpack___024root* vlSelf);
void VFP21_pack_unpack___024root___eval(VFP21_pack_unpack___024root* vlSelf);

void VFP21_pack_unpack::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VFP21_pack_unpack::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VFP21_pack_unpack___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VFP21_pack_unpack___024root___eval_static(&(vlSymsp->TOP));
        VFP21_pack_unpack___024root___eval_initial(&(vlSymsp->TOP));
        VFP21_pack_unpack___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VFP21_pack_unpack___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VFP21_pack_unpack::eventsPending() { return false; }

uint64_t VFP21_pack_unpack::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VFP21_pack_unpack::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VFP21_pack_unpack___024root___eval_final(VFP21_pack_unpack___024root* vlSelf);

VL_ATTR_COLD void VFP21_pack_unpack::final() {
    VFP21_pack_unpack___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VFP21_pack_unpack::hierName() const { return vlSymsp->name(); }
const char* VFP21_pack_unpack::modelName() const { return "VFP21_pack_unpack"; }
unsigned VFP21_pack_unpack::threads() const { return 1; }
void VFP21_pack_unpack::prepareClone() const { contextp()->prepareClone(); }
void VFP21_pack_unpack::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> VFP21_pack_unpack::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void VFP21_pack_unpack___024root__trace_decl_types(VerilatedVcd* tracep);

void VFP21_pack_unpack___024root__trace_init_top(VFP21_pack_unpack___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VFP21_pack_unpack___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VFP21_pack_unpack___024root*>(voidSelf);
    VFP21_pack_unpack__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    VFP21_pack_unpack___024root__trace_decl_types(tracep);
    VFP21_pack_unpack___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void VFP21_pack_unpack___024root__trace_register(VFP21_pack_unpack___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VFP21_pack_unpack::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'VFP21_pack_unpack::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    VFP21_pack_unpack___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
