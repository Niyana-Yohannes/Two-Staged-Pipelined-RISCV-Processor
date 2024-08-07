// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtestbench.h for the primary calling header

#include "Vtestbench.h"
#include "Vtestbench__Syms.h"

//==========

void Vtestbench::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtestbench::eval\n"); );
    Vtestbench__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtestbench* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("testbench.sv", 20, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vtestbench::_eval_initial_loop(Vtestbench__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("testbench.sv", 20, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vtestbench::_sequent__TOP__1(Vtestbench__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench::_sequent__TOP__1\n"); );
    Vtestbench* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*7:0*/ __Vdlyvval__testbench__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__testbench__DOT__mem__v0;
    CData/*7:0*/ __Vdlyvval__testbench__DOT__mem__v1;
    CData/*0:0*/ __Vdlyvset__testbench__DOT__mem__v1;
    CData/*7:0*/ __Vdlyvval__testbench__DOT__mem__v2;
    CData/*0:0*/ __Vdlyvset__testbench__DOT__mem__v2;
    CData/*7:0*/ __Vdlyvval__testbench__DOT__mem__v3;
    CData/*0:0*/ __Vdlyvset__testbench__DOT__mem__v3;
    CData/*4:0*/ __Vdlyvdim0__testbench__DOT__dut__DOT__regfile__v0;
    CData/*0:0*/ __Vdlyvset__testbench__DOT__dut__DOT__regfile__v0;
    SData/*15:0*/ __Vdlyvdim0__testbench__DOT__mem__v0;
    SData/*15:0*/ __Vdlyvdim0__testbench__DOT__mem__v1;
    SData/*15:0*/ __Vdlyvdim0__testbench__DOT__mem__v2;
    SData/*15:0*/ __Vdlyvdim0__testbench__DOT__mem__v3;
    IData/*31:0*/ __Vdly__testbench__DOT__cycles;
    IData/*31:0*/ __Vdlyvval__testbench__DOT__dut__DOT__regfile__v0;
    // Body
    __Vdly__testbench__DOT__cycles = vlTOPp->testbench__DOT__cycles;
    __Vdlyvset__testbench__DOT__mem__v0 = 0U;
    __Vdlyvset__testbench__DOT__mem__v1 = 0U;
    __Vdlyvset__testbench__DOT__mem__v2 = 0U;
    __Vdlyvset__testbench__DOT__mem__v3 = 0U;
    __Vdlyvset__testbench__DOT__dut__DOT__regfile__v0 = 0U;
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (vlTOPp->testbench__DOT__dmem_valid) {
            vlTOPp->testbench__DOT__i = 4U;
        }
    }
    if (VL_UNLIKELY((0x10000U <= vlTOPp->testbench__DOT__imem_addr))) {
        VL_WRITEF("Memory access out of range: imem_addr = 0x%08x\n",
                  32,vlTOPp->testbench__DOT__imem_addr);
    }
    if (VL_UNLIKELY(((IData)(vlTOPp->testbench__DOT__dmem_valid) 
                     & (~ ((0x10000U > (0x3fffffffU 
                                        & (vlTOPp->testbench__DOT__dmem_addr 
                                           >> 2U))) 
                           | (0x2000000U == vlTOPp->testbench__DOT__dmem_addr)))))) {
        VL_WRITEF("Memory access out of range: dmem_addr = 0x%08x\n",
                  32,vlTOPp->testbench__DOT__dmem_addr);
    }
    if (VL_UNLIKELY(vlTOPp->testbench__DOT__out_valid)) {
        VL_WRITEF("%c",8,(0xffU & vlTOPp->testbench__DOT__out));
    }
    __Vdly__testbench__DOT__cycles = ((IData)(1U) + vlTOPp->testbench__DOT__cycles);
    if (VL_UNLIKELY(vlTOPp->testbench__DOT__dut__DOT__trapped)) {
        VL_WRITEF("Simulated %0# cycles\n",32,vlTOPp->testbench__DOT__cycles);
        VL_FINISH_MT("testbench.sv", 127, "");
    }
    vlTOPp->testbench__DOT__dut__DOT__imem_addr_q = vlTOPp->testbench__DOT__imem_addr;
    vlTOPp->testbench__DOT__dut__DOT__mem_rd_func_q 
        = vlTOPp->testbench__DOT__dut__DOT__mem_rd_func;
    vlTOPp->testbench__DOT__dut__DOT__imm_s_sext = 
        VL_EXTENDS_II(32,12, (IData)(vlTOPp->testbench__DOT__dut__DOT__imm_s));
    vlTOPp->testbench__DOT__dut__DOT__imm_b_sext = 
        VL_EXTENDS_II(32,13, (IData)(vlTOPp->testbench__DOT__dut__DOT__imm_b));
    vlTOPp->testbench__DOT__dut__DOT__imm_j_sext = 
        VL_EXTENDS_II(32,21, vlTOPp->testbench__DOT__dut__DOT__imm_j);
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (vlTOPp->testbench__DOT__dmem_valid) {
            if ((1U & (IData)(vlTOPp->testbench__DOT__dmem_wstrb))) {
                if ((0x10000U > (0x3fffffffU & (vlTOPp->testbench__DOT__dmem_addr 
                                                >> 2U)))) {
                    __Vdlyvval__testbench__DOT__mem__v0 
                        = (0xffU & vlTOPp->testbench__DOT__dmem_wdata);
                    __Vdlyvset__testbench__DOT__mem__v0 = 1U;
                    __Vdlyvdim0__testbench__DOT__mem__v0 
                        = (0xfffcU & vlTOPp->testbench__DOT__dmem_addr);
                }
            }
            if ((2U & (IData)(vlTOPp->testbench__DOT__dmem_wstrb))) {
                if ((0x10000U > (0x3fffffffU & (vlTOPp->testbench__DOT__dmem_addr 
                                                >> 2U)))) {
                    __Vdlyvval__testbench__DOT__mem__v1 
                        = (0xffU & (vlTOPp->testbench__DOT__dmem_wdata 
                                    >> 8U));
                    __Vdlyvset__testbench__DOT__mem__v1 = 1U;
                    __Vdlyvdim0__testbench__DOT__mem__v1 
                        = (1U | (0xfffcU & vlTOPp->testbench__DOT__dmem_addr));
                }
            }
            if ((4U & (IData)(vlTOPp->testbench__DOT__dmem_wstrb))) {
                if ((0x10000U > (0x3fffffffU & (vlTOPp->testbench__DOT__dmem_addr 
                                                >> 2U)))) {
                    __Vdlyvval__testbench__DOT__mem__v2 
                        = (0xffU & (vlTOPp->testbench__DOT__dmem_wdata 
                                    >> 0x10U));
                    __Vdlyvset__testbench__DOT__mem__v2 = 1U;
                    __Vdlyvdim0__testbench__DOT__mem__v2 
                        = (2U | (0xfffcU & vlTOPp->testbench__DOT__dmem_addr));
                }
            }
            if ((8U & (IData)(vlTOPp->testbench__DOT__dmem_wstrb))) {
                if ((0x10000U > (0x3fffffffU & (vlTOPp->testbench__DOT__dmem_addr 
                                                >> 2U)))) {
                    __Vdlyvval__testbench__DOT__mem__v3 
                        = (0xffU & (vlTOPp->testbench__DOT__dmem_wdata 
                                    >> 0x18U));
                    __Vdlyvset__testbench__DOT__mem__v3 = 1U;
                    __Vdlyvdim0__testbench__DOT__mem__v3 
                        = (3U | (0xfffcU & vlTOPp->testbench__DOT__dmem_addr));
                }
            }
        }
    }
    vlTOPp->testbench__DOT__dut__DOT__stall_stage2 
        = vlTOPp->testbench__DOT__dut__DOT__stall;
    vlTOPp->testbench__DOT__dut__DOT__imm_i_sext = 
        VL_EXTENDS_II(32,12, (0xfffU & (vlTOPp->testbench__DOT__imem_data 
                                        >> 0x14U)));
    vlTOPp->testbench__DOT__dut__DOT__rs2_value = ((IData)(vlTOPp->testbench__DOT__dut__DOT__bypass_rs2)
                                                    ? vlTOPp->testbench__DOT__dut__DOT__next_rd
                                                    : 
                                                   ((0U 
                                                     != 
                                                     (0x1fU 
                                                      & (vlTOPp->testbench__DOT__imem_data 
                                                         >> 0x14U)))
                                                     ? 
                                                    vlTOPp->testbench__DOT__dut__DOT__regfile
                                                    [
                                                    (0x1fU 
                                                     & (vlTOPp->testbench__DOT__imem_data 
                                                        >> 0x14U))]
                                                     : 0U));
    vlTOPp->testbench__DOT__dut__DOT__rs1_value = ((IData)(vlTOPp->testbench__DOT__dut__DOT__bypass_rs1)
                                                    ? vlTOPp->testbench__DOT__dut__DOT__next_rd
                                                    : 
                                                   ((0U 
                                                     != 
                                                     (0x1fU 
                                                      & (vlTOPp->testbench__DOT__imem_data 
                                                         >> 0xfU)))
                                                     ? 
                                                    vlTOPp->testbench__DOT__dut__DOT__regfile
                                                    [
                                                    (0x1fU 
                                                     & (vlTOPp->testbench__DOT__imem_data 
                                                        >> 0xfU))]
                                                     : 0U));
    vlTOPp->testbench__DOT__dut__DOT__ppc = vlTOPp->testbench__DOT__dut__DOT__pc;
    vlTOPp->testbench__DOT__dut__DOT__kill_jmp_stage2 
        = vlTOPp->testbench__DOT__dut__DOT__kill_jmp;
    if ((0xfffffffcU == vlTOPp->testbench__DOT__dut__DOT__pc)) {
        vlTOPp->testbench__DOT__dut__DOT__kill_jmp_stage2 = 0U;
    }
    vlTOPp->testbench__DOT__cycles = __Vdly__testbench__DOT__cycles;
    vlTOPp->testbench__DOT__out_valid = 0U;
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (vlTOPp->testbench__DOT__dmem_valid) {
            if ((1U & (IData)(vlTOPp->testbench__DOT__dmem_wstrb))) {
                if ((0x2000000U == vlTOPp->testbench__DOT__dmem_addr)) {
                    vlTOPp->testbench__DOT__out_valid = 1U;
                }
            }
            if ((2U & (IData)(vlTOPp->testbench__DOT__dmem_wstrb))) {
                if ((0x2000000U == vlTOPp->testbench__DOT__dmem_addr)) {
                    vlTOPp->testbench__DOT__out_valid = 1U;
                }
            }
            if ((4U & (IData)(vlTOPp->testbench__DOT__dmem_wstrb))) {
                if ((0x2000000U == vlTOPp->testbench__DOT__dmem_addr)) {
                    vlTOPp->testbench__DOT__out_valid = 1U;
                }
            }
            if ((8U & (IData)(vlTOPp->testbench__DOT__dmem_wstrb))) {
                if ((0x2000000U == vlTOPp->testbench__DOT__dmem_addr)) {
                    vlTOPp->testbench__DOT__out_valid = 1U;
                }
            }
        }
    }
    vlTOPp->testbench__DOT__out = 0U;
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (vlTOPp->testbench__DOT__dmem_valid) {
            if ((1U & (IData)(vlTOPp->testbench__DOT__dmem_wstrb))) {
                if ((0x2000000U == vlTOPp->testbench__DOT__dmem_addr)) {
                    vlTOPp->testbench__DOT__out = (
                                                   (0xffffff00U 
                                                    & vlTOPp->testbench__DOT__out) 
                                                   | (0xffU 
                                                      & vlTOPp->testbench__DOT__dmem_wdata));
                }
            }
            if ((2U & (IData)(vlTOPp->testbench__DOT__dmem_wstrb))) {
                if ((0x2000000U == vlTOPp->testbench__DOT__dmem_addr)) {
                    vlTOPp->testbench__DOT__out = (
                                                   (0xffff00ffU 
                                                    & vlTOPp->testbench__DOT__out) 
                                                   | (0xff00U 
                                                      & vlTOPp->testbench__DOT__dmem_wdata));
                }
            }
            if ((4U & (IData)(vlTOPp->testbench__DOT__dmem_wstrb))) {
                if ((0x2000000U == vlTOPp->testbench__DOT__dmem_addr)) {
                    vlTOPp->testbench__DOT__out = (
                                                   (0xff00ffffU 
                                                    & vlTOPp->testbench__DOT__out) 
                                                   | (0xff0000U 
                                                      & vlTOPp->testbench__DOT__dmem_wdata));
                }
            }
            if ((8U & (IData)(vlTOPp->testbench__DOT__dmem_wstrb))) {
                if ((0x2000000U == vlTOPp->testbench__DOT__dmem_addr)) {
                    vlTOPp->testbench__DOT__out = (
                                                   (0xffffffU 
                                                    & vlTOPp->testbench__DOT__out) 
                                                   | (0xff000000U 
                                                      & vlTOPp->testbench__DOT__dmem_wdata));
                }
            }
        }
    }
    vlTOPp->testbench__DOT__dut__DOT__trapped_q = vlTOPp->testbench__DOT__dut__DOT__trapped;
    if ((1U & (((~ (IData)(vlTOPp->testbench__DOT__dut__DOT__trapped)) 
                & (~ (IData)(vlTOPp->reset))) & (~ (IData)(vlTOPp->testbench__DOT__dut__DOT__reset_q))))) {
        if (vlTOPp->testbench__DOT__dut__DOT__illinsn) {
            vlTOPp->testbench__DOT__dut__DOT__trapped = 1U;
        }
        vlTOPp->testbench__DOT__dut__DOT__pc = vlTOPp->testbench__DOT__dut__DOT__npc;
        vlTOPp->testbench__DOT__x10 = vlTOPp->testbench__DOT__dut__DOT__regfile
            [0xaU];
        if ((((IData)(vlTOPp->testbench__DOT__dut__DOT__mem_rd_enable_q) 
              | (IData)(vlTOPp->testbench__DOT__dut__DOT__next_wr_stall)) 
             | (IData)(vlTOPp->testbench__DOT__dut__DOT__next_wr_bypass))) {
            __Vdlyvval__testbench__DOT__dut__DOT__regfile__v0 
                = ((IData)(vlTOPp->testbench__DOT__dut__DOT__mem_rd_enable_q)
                    ? vlTOPp->testbench__DOT__dut__DOT__mem_rdata
                    : vlTOPp->testbench__DOT__dut__DOT__next_rd);
            __Vdlyvset__testbench__DOT__dut__DOT__regfile__v0 = 1U;
            __Vdlyvdim0__testbench__DOT__dut__DOT__regfile__v0 
                = (0x1fU & ((IData)(vlTOPp->testbench__DOT__dut__DOT__mem_rd_enable_q)
                             ? (IData)(vlTOPp->testbench__DOT__dut__DOT__mem_rd_reg_q)
                             : (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                >> 7U)));
        }
    }
    if (((IData)(vlTOPp->reset) | (IData)(vlTOPp->testbench__DOT__dut__DOT__reset_q))) {
        vlTOPp->testbench__DOT__dut__DOT__pc = (- ((IData)(vlTOPp->reset)
                                                    ? 4U
                                                    : 0U));
        vlTOPp->testbench__DOT__dut__DOT__trapped = 0U;
    }
    if (__Vdlyvset__testbench__DOT__dut__DOT__regfile__v0) {
        vlTOPp->testbench__DOT__dut__DOT__regfile[__Vdlyvdim0__testbench__DOT__dut__DOT__regfile__v0] 
            = __Vdlyvval__testbench__DOT__dut__DOT__regfile__v0;
    }
    vlTOPp->testbench__DOT__dut__DOT__mem_rd_reg_q 
        = vlTOPp->testbench__DOT__dut__DOT__mem_rd_reg;
    vlTOPp->testbench__DOT__dut__DOT__reset_q = vlTOPp->reset;
    vlTOPp->testbench__DOT__dut__DOT__mem_rd_enable_q 
        = vlTOPp->testbench__DOT__dut__DOT__mem_rd_enable;
    if (vlTOPp->reset) {
        vlTOPp->testbench__DOT__dut__DOT__mem_rd_enable_q = 0U;
    }
    vlTOPp->testbench__DOT__dut__DOT__insn_stage2 = vlTOPp->testbench__DOT__imem_data;
    vlTOPp->testbench__DOT__dut__DOT__kill_jmp = 0U;
    if ((1U & (((~ (IData)(vlTOPp->testbench__DOT__dut__DOT__stall_stage2)) 
                & (~ (IData)(vlTOPp->testbench__DOT__dut__DOT__kill_jmp_stage2))) 
               & (~ (IData)(vlTOPp->testbench__DOT__dut__DOT__mem_rd_enable_q))))) {
        if ((0x40U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
            if ((0x20U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                if ((1U & (~ (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                              >> 4U)))) {
                    if ((8U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                        if ((4U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                            if ((2U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                                if ((1U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                                    vlTOPp->testbench__DOT__dut__DOT__kill_jmp = 1U;
                                }
                            }
                        }
                    } else {
                        if ((4U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                            if ((2U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                                if ((1U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                                    vlTOPp->testbench__DOT__dut__DOT__kill_jmp = 1U;
                                }
                            }
                        } else {
                            if ((2U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                                if ((1U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                                    if ((0x4000U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                                        if ((0x2000U 
                                             & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                                            if ((0x1000U 
                                                 & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                                                if (
                                                    (vlTOPp->testbench__DOT__dut__DOT__rs1_value 
                                                     >= vlTOPp->testbench__DOT__dut__DOT__rs2_value)) {
                                                    vlTOPp->testbench__DOT__dut__DOT__kill_jmp = 1U;
                                                }
                                            } else {
                                                if (
                                                    (vlTOPp->testbench__DOT__dut__DOT__rs1_value 
                                                     < vlTOPp->testbench__DOT__dut__DOT__rs2_value)) {
                                                    vlTOPp->testbench__DOT__dut__DOT__kill_jmp = 1U;
                                                }
                                            }
                                        } else {
                                            if ((0x1000U 
                                                 & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                                                if (
                                                    VL_GTES_III(1,32,32, vlTOPp->testbench__DOT__dut__DOT__rs1_value, vlTOPp->testbench__DOT__dut__DOT__rs2_value)) {
                                                    vlTOPp->testbench__DOT__dut__DOT__kill_jmp = 1U;
                                                }
                                            } else {
                                                if (
                                                    VL_LTS_III(1,32,32, vlTOPp->testbench__DOT__dut__DOT__rs1_value, vlTOPp->testbench__DOT__dut__DOT__rs2_value)) {
                                                    vlTOPp->testbench__DOT__dut__DOT__kill_jmp = 1U;
                                                }
                                            }
                                        }
                                    } else {
                                        if ((1U & (~ 
                                                   (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                    >> 0xdU)))) {
                                            if ((0x1000U 
                                                 & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                                                if (
                                                    (vlTOPp->testbench__DOT__dut__DOT__rs1_value 
                                                     != vlTOPp->testbench__DOT__dut__DOT__rs2_value)) {
                                                    vlTOPp->testbench__DOT__dut__DOT__kill_jmp = 1U;
                                                }
                                            } else {
                                                if (
                                                    (vlTOPp->testbench__DOT__dut__DOT__rs1_value 
                                                     == vlTOPp->testbench__DOT__dut__DOT__rs2_value)) {
                                                    vlTOPp->testbench__DOT__dut__DOT__kill_jmp = 1U;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->testbench__DOT__dut__DOT__next_rd = 0U;
    if ((1U & (((~ (IData)(vlTOPp->testbench__DOT__dut__DOT__stall_stage2)) 
                & (~ (IData)(vlTOPp->testbench__DOT__dut__DOT__kill_jmp_stage2))) 
               & (~ (IData)(vlTOPp->testbench__DOT__dut__DOT__mem_rd_enable_q))))) {
        if ((0x40U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
            if ((0x20U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                if ((1U & (~ (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                              >> 4U)))) {
                    if ((8U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                        if ((4U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                            if ((2U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                                if ((1U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                                    vlTOPp->testbench__DOT__dut__DOT__next_rd 
                                        = ((IData)(4U) 
                                           + vlTOPp->testbench__DOT__dut__DOT__ppc);
                                }
                            }
                        }
                    } else {
                        if ((4U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                            if ((2U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                                if ((1U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                                    if ((0U == (7U 
                                                & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                   >> 0xcU)))) {
                                        vlTOPp->testbench__DOT__dut__DOT__next_rd 
                                            = ((IData)(4U) 
                                               + vlTOPp->testbench__DOT__dut__DOT__ppc);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if ((0x20U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                if ((0x10U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                    if ((1U & (~ (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                  >> 3U)))) {
                        if ((4U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                            if ((2U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                                if ((1U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                                    vlTOPp->testbench__DOT__dut__DOT__next_rd 
                                        = (0xfffff000U 
                                           & vlTOPp->testbench__DOT__dut__DOT__insn_stage2);
                                }
                            }
                        } else {
                            if ((2U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                                if ((1U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                                    if (((((((((0U 
                                                == 
                                                ((0x3f8U 
                                                  & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                     >> 0x16U)) 
                                                 | (7U 
                                                    & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                       >> 0xcU)))) 
                                               | (0x100U 
                                                  == 
                                                  ((0x3f8U 
                                                    & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                       >> 0x16U)) 
                                                   | (7U 
                                                      & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                         >> 0xcU))))) 
                                              | (1U 
                                                 == 
                                                 ((0x3f8U 
                                                   & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                      >> 0x16U)) 
                                                  | (7U 
                                                     & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                        >> 0xcU))))) 
                                             | (2U 
                                                == 
                                                ((0x3f8U 
                                                  & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                     >> 0x16U)) 
                                                 | (7U 
                                                    & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                       >> 0xcU))))) 
                                            | (3U == 
                                               ((0x3f8U 
                                                 & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                    >> 0x16U)) 
                                                | (7U 
                                                   & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                      >> 0xcU))))) 
                                           | (4U == 
                                              ((0x3f8U 
                                                & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                   >> 0x16U)) 
                                               | (7U 
                                                  & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                     >> 0xcU))))) 
                                          | (5U == 
                                             ((0x3f8U 
                                               & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                  >> 0x16U)) 
                                              | (7U 
                                                 & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                    >> 0xcU))))) 
                                         | (0x105U 
                                            == ((0x3f8U 
                                                 & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                    >> 0x16U)) 
                                                | (7U 
                                                   & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                      >> 0xcU)))))) {
                                        vlTOPp->testbench__DOT__dut__DOT__next_rd 
                                            = ((0U 
                                                == 
                                                ((0x3f8U 
                                                  & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                     >> 0x16U)) 
                                                 | (7U 
                                                    & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                       >> 0xcU))))
                                                ? (vlTOPp->testbench__DOT__dut__DOT__rs1_value 
                                                   + vlTOPp->testbench__DOT__dut__DOT__rs2_value)
                                                : (
                                                   (0x100U 
                                                    == 
                                                    ((0x3f8U 
                                                      & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                         >> 0x16U)) 
                                                     | (7U 
                                                        & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                           >> 0xcU))))
                                                    ? 
                                                   (vlTOPp->testbench__DOT__dut__DOT__rs1_value 
                                                    - vlTOPp->testbench__DOT__dut__DOT__rs2_value)
                                                    : 
                                                   ((1U 
                                                     == 
                                                     ((0x3f8U 
                                                       & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                          >> 0x16U)) 
                                                      | (7U 
                                                         & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                            >> 0xcU))))
                                                     ? 
                                                    (vlTOPp->testbench__DOT__dut__DOT__rs1_value 
                                                     << 
                                                     (0x1fU 
                                                      & vlTOPp->testbench__DOT__dut__DOT__rs2_value))
                                                     : 
                                                    ((2U 
                                                      == 
                                                      ((0x3f8U 
                                                        & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                           >> 0x16U)) 
                                                       | (7U 
                                                          & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                             >> 0xcU))))
                                                      ? 
                                                     VL_LTS_III(32,32,32, vlTOPp->testbench__DOT__dut__DOT__rs1_value, vlTOPp->testbench__DOT__dut__DOT__rs2_value)
                                                      : 
                                                     ((3U 
                                                       == 
                                                       ((0x3f8U 
                                                         & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                            >> 0x16U)) 
                                                        | (7U 
                                                           & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                              >> 0xcU))))
                                                       ? 
                                                      (vlTOPp->testbench__DOT__dut__DOT__rs1_value 
                                                       < vlTOPp->testbench__DOT__dut__DOT__rs2_value)
                                                       : 
                                                      ((4U 
                                                        == 
                                                        ((0x3f8U 
                                                          & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                             >> 0x16U)) 
                                                         | (7U 
                                                            & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                               >> 0xcU))))
                                                        ? 
                                                       (vlTOPp->testbench__DOT__dut__DOT__rs1_value 
                                                        ^ vlTOPp->testbench__DOT__dut__DOT__rs2_value)
                                                        : 
                                                       ((5U 
                                                         == 
                                                         ((0x3f8U 
                                                           & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                              >> 0x16U)) 
                                                          | (7U 
                                                             & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                                >> 0xcU))))
                                                         ? 
                                                        (vlTOPp->testbench__DOT__dut__DOT__rs1_value 
                                                         >> 
                                                         (0x1fU 
                                                          & vlTOPp->testbench__DOT__dut__DOT__rs2_value))
                                                         : 
                                                        VL_SHIFTRS_III(32,32,5, vlTOPp->testbench__DOT__dut__DOT__rs1_value, 
                                                                       (0x1fU 
                                                                        & vlTOPp->testbench__DOT__dut__DOT__rs2_value)))))))));
                                    } else {
                                        if ((6U == 
                                             ((0x3f8U 
                                               & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                  >> 0x16U)) 
                                              | (7U 
                                                 & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                    >> 0xcU))))) {
                                            vlTOPp->testbench__DOT__dut__DOT__next_rd 
                                                = (vlTOPp->testbench__DOT__dut__DOT__rs1_value 
                                                   | vlTOPp->testbench__DOT__dut__DOT__rs2_value);
                                        } else {
                                            if ((7U 
                                                 == 
                                                 ((0x3f8U 
                                                   & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                      >> 0x16U)) 
                                                  | (7U 
                                                     & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                        >> 0xcU))))) {
                                                vlTOPp->testbench__DOT__dut__DOT__next_rd 
                                                    = 
                                                    (vlTOPp->testbench__DOT__dut__DOT__rs1_value 
                                                     & vlTOPp->testbench__DOT__dut__DOT__rs2_value);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            } else {
                if ((0x10U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                    if ((1U & (~ (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                  >> 3U)))) {
                        if ((4U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                            if ((2U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                                if ((1U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                                    vlTOPp->testbench__DOT__dut__DOT__next_rd 
                                        = ((0xfffff000U 
                                            & vlTOPp->testbench__DOT__dut__DOT__insn_stage2) 
                                           + vlTOPp->testbench__DOT__dut__DOT__pc);
                                }
                            }
                        } else {
                            if ((2U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                                if ((1U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                                    if (((((((((0U 
                                                == 
                                                (7U 
                                                 & ((0x3f8U 
                                                     & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                        >> 0x16U)) 
                                                    | (7U 
                                                       & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                          >> 0xcU))))) 
                                               | (2U 
                                                  == 
                                                  (7U 
                                                   & ((0x3f8U 
                                                       & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                          >> 0x16U)) 
                                                      | (7U 
                                                         & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                            >> 0xcU)))))) 
                                              | (3U 
                                                 == 
                                                 (7U 
                                                  & ((0x3f8U 
                                                      & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                         >> 0x16U)) 
                                                     | (7U 
                                                        & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                           >> 0xcU)))))) 
                                             | (4U 
                                                == 
                                                (7U 
                                                 & ((0x3f8U 
                                                     & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                        >> 0x16U)) 
                                                    | (7U 
                                                       & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                          >> 0xcU)))))) 
                                            | (6U == 
                                               (7U 
                                                & ((0x3f8U 
                                                    & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                       >> 0x16U)) 
                                                   | (7U 
                                                      & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                         >> 0xcU)))))) 
                                           | (7U == 
                                              (7U & 
                                               ((0x3f8U 
                                                 & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                    >> 0x16U)) 
                                                | (7U 
                                                   & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                      >> 0xcU)))))) 
                                          | (1U == 
                                             ((0x3f8U 
                                               & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                  >> 0x16U)) 
                                              | (7U 
                                                 & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                    >> 0xcU))))) 
                                         | (5U == (
                                                   (0x3f8U 
                                                    & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                       >> 0x16U)) 
                                                   | (7U 
                                                      & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                         >> 0xcU)))))) {
                                        vlTOPp->testbench__DOT__dut__DOT__next_rd 
                                            = ((0U 
                                                == 
                                                (7U 
                                                 & ((0x3f8U 
                                                     & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                        >> 0x16U)) 
                                                    | (7U 
                                                       & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                          >> 0xcU)))))
                                                ? (vlTOPp->testbench__DOT__dut__DOT__rs1_value 
                                                   + vlTOPp->testbench__DOT__dut__DOT__imm_i_sext)
                                                : (
                                                   (2U 
                                                    == 
                                                    (7U 
                                                     & ((0x3f8U 
                                                         & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                            >> 0x16U)) 
                                                        | (7U 
                                                           & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                              >> 0xcU)))))
                                                    ? 
                                                   VL_LTS_III(32,32,32, vlTOPp->testbench__DOT__dut__DOT__rs1_value, vlTOPp->testbench__DOT__dut__DOT__imm_i_sext)
                                                    : 
                                                   ((3U 
                                                     == 
                                                     (7U 
                                                      & ((0x3f8U 
                                                          & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                             >> 0x16U)) 
                                                         | (7U 
                                                            & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                               >> 0xcU)))))
                                                     ? 
                                                    (vlTOPp->testbench__DOT__dut__DOT__rs1_value 
                                                     < vlTOPp->testbench__DOT__dut__DOT__imm_i_sext)
                                                     : 
                                                    ((4U 
                                                      == 
                                                      (7U 
                                                       & ((0x3f8U 
                                                           & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                              >> 0x16U)) 
                                                          | (7U 
                                                             & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                                >> 0xcU)))))
                                                      ? 
                                                     (vlTOPp->testbench__DOT__dut__DOT__rs1_value 
                                                      ^ vlTOPp->testbench__DOT__dut__DOT__imm_i_sext)
                                                      : 
                                                     ((6U 
                                                       == 
                                                       (7U 
                                                        & ((0x3f8U 
                                                            & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                               >> 0x16U)) 
                                                           | (7U 
                                                              & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                                 >> 0xcU)))))
                                                       ? 
                                                      (vlTOPp->testbench__DOT__dut__DOT__rs1_value 
                                                       | vlTOPp->testbench__DOT__dut__DOT__imm_i_sext)
                                                       : 
                                                      ((7U 
                                                        == 
                                                        (7U 
                                                         & ((0x3f8U 
                                                             & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                                >> 0x16U)) 
                                                            | (7U 
                                                               & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                                  >> 0xcU)))))
                                                        ? 
                                                       (vlTOPp->testbench__DOT__dut__DOT__rs1_value 
                                                        & vlTOPp->testbench__DOT__dut__DOT__imm_i_sext)
                                                        : 
                                                       ((1U 
                                                         == 
                                                         ((0x3f8U 
                                                           & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                              >> 0x16U)) 
                                                          | (7U 
                                                             & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                                >> 0xcU))))
                                                         ? 
                                                        (vlTOPp->testbench__DOT__dut__DOT__rs1_value 
                                                         << 
                                                         (0x1fU 
                                                          & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                             >> 0x14U)))
                                                         : 
                                                        (vlTOPp->testbench__DOT__dut__DOT__rs1_value 
                                                         >> 
                                                         (0x1fU 
                                                          & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                             >> 0x14U))))))))));
                                    } else {
                                        if ((0x105U 
                                             == ((0x3f8U 
                                                  & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                     >> 0x16U)) 
                                                 | (7U 
                                                    & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                       >> 0xcU))))) {
                                            vlTOPp->testbench__DOT__dut__DOT__next_rd 
                                                = VL_SHIFTRS_III(32,32,5, vlTOPp->testbench__DOT__dut__DOT__rs1_value, 
                                                                 (0x1fU 
                                                                  & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                                     >> 0x14U)));
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->testbench__DOT__imem_data = ((vlTOPp->testbench__DOT__mem
                                          [(3U | (0xfffcU 
                                                  & vlTOPp->testbench__DOT__imem_addr))] 
                                          << 0x18U) 
                                         | ((vlTOPp->testbench__DOT__mem
                                             [(2U | 
                                               (0xfffcU 
                                                & vlTOPp->testbench__DOT__imem_addr))] 
                                             << 0x10U) 
                                            | ((vlTOPp->testbench__DOT__mem
                                                [(1U 
                                                  | (0xfffcU 
                                                     & vlTOPp->testbench__DOT__imem_addr))] 
                                                << 8U) 
                                               | vlTOPp->testbench__DOT__mem
                                               [(0xfffcU 
                                                 & vlTOPp->testbench__DOT__imem_addr)])));
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (vlTOPp->testbench__DOT__dmem_valid) {
            vlTOPp->testbench__DOT__dmem_rdata = ((
                                                   vlTOPp->testbench__DOT__mem
                                                   [
                                                   (3U 
                                                    | (0xfffcU 
                                                       & vlTOPp->testbench__DOT__dmem_addr))] 
                                                   << 0x18U) 
                                                  | ((vlTOPp->testbench__DOT__mem
                                                      [
                                                      (2U 
                                                       | (0xfffcU 
                                                          & vlTOPp->testbench__DOT__dmem_addr))] 
                                                      << 0x10U) 
                                                     | ((vlTOPp->testbench__DOT__mem
                                                         [
                                                         (1U 
                                                          | (0xfffcU 
                                                             & vlTOPp->testbench__DOT__dmem_addr))] 
                                                         << 8U) 
                                                        | vlTOPp->testbench__DOT__mem
                                                        [
                                                        (0xfffcU 
                                                         & vlTOPp->testbench__DOT__dmem_addr)])));
            if ((1U & (IData)(vlTOPp->testbench__DOT__dmem_wstrb))) {
                vlTOPp->testbench__DOT__dmem_rdata = 0U;
            }
            if ((2U & (IData)(vlTOPp->testbench__DOT__dmem_wstrb))) {
                vlTOPp->testbench__DOT__dmem_rdata = 0U;
            }
            if ((4U & (IData)(vlTOPp->testbench__DOT__dmem_wstrb))) {
                vlTOPp->testbench__DOT__dmem_rdata = 0U;
            }
            if ((8U & (IData)(vlTOPp->testbench__DOT__dmem_wstrb))) {
                vlTOPp->testbench__DOT__dmem_rdata = 0U;
            }
        } else {
            vlTOPp->testbench__DOT__dmem_rdata = 0U;
        }
    }
    if (__Vdlyvset__testbench__DOT__mem__v0) {
        vlTOPp->testbench__DOT__mem[__Vdlyvdim0__testbench__DOT__mem__v0] 
            = __Vdlyvval__testbench__DOT__mem__v0;
    }
    if (__Vdlyvset__testbench__DOT__mem__v1) {
        vlTOPp->testbench__DOT__mem[__Vdlyvdim0__testbench__DOT__mem__v1] 
            = __Vdlyvval__testbench__DOT__mem__v1;
    }
    if (__Vdlyvset__testbench__DOT__mem__v2) {
        vlTOPp->testbench__DOT__mem[__Vdlyvdim0__testbench__DOT__mem__v2] 
            = __Vdlyvval__testbench__DOT__mem__v2;
    }
    if (__Vdlyvset__testbench__DOT__mem__v3) {
        vlTOPp->testbench__DOT__mem[__Vdlyvdim0__testbench__DOT__mem__v3] 
            = __Vdlyvval__testbench__DOT__mem__v3;
    }
    vlTOPp->testbench__DOT__dut__DOT__mem_rdata = (
                                                   (0x1fU 
                                                    >= 
                                                    (0x18U 
                                                     & (IData)(vlTOPp->testbench__DOT__dut__DOT__mem_rd_func_q)))
                                                    ? 
                                                   (vlTOPp->testbench__DOT__dmem_rdata 
                                                    >> 
                                                    (0x18U 
                                                     & (IData)(vlTOPp->testbench__DOT__dut__DOT__mem_rd_func_q)))
                                                    : 0U);
    if ((0U == (7U & (IData)(vlTOPp->testbench__DOT__dut__DOT__mem_rd_func_q)))) {
        vlTOPp->testbench__DOT__dut__DOT__mem_rdata 
            = VL_EXTENDS_II(32,8, (0xffU & vlTOPp->testbench__DOT__dut__DOT__mem_rdata));
    } else {
        if ((1U == (7U & (IData)(vlTOPp->testbench__DOT__dut__DOT__mem_rd_func_q)))) {
            vlTOPp->testbench__DOT__dut__DOT__mem_rdata 
                = VL_EXTENDS_II(32,16, (0xffffU & vlTOPp->testbench__DOT__dut__DOT__mem_rdata));
        } else {
            if ((4U == (7U & (IData)(vlTOPp->testbench__DOT__dut__DOT__mem_rd_func_q)))) {
                vlTOPp->testbench__DOT__dut__DOT__mem_rdata 
                    = (0xffU & vlTOPp->testbench__DOT__dut__DOT__mem_rdata);
            } else {
                if ((5U == (7U & (IData)(vlTOPp->testbench__DOT__dut__DOT__mem_rd_func_q)))) {
                    vlTOPp->testbench__DOT__dut__DOT__mem_rdata 
                        = (0xffffU & vlTOPp->testbench__DOT__dut__DOT__mem_rdata);
                }
            }
        }
    }
    vlTOPp->testbench__DOT__dut__DOT__imm_s = ((0xfe0U 
                                                & (vlTOPp->testbench__DOT__imem_data 
                                                   >> 0x14U)) 
                                               | (0x1fU 
                                                  & (vlTOPp->testbench__DOT__imem_data 
                                                     >> 7U)));
    vlTOPp->testbench__DOT__dut__DOT__imm_b = ((0xfffU 
                                                & (IData)(vlTOPp->testbench__DOT__dut__DOT__imm_b)) 
                                               | (0x1000U 
                                                  & (vlTOPp->testbench__DOT__imem_data 
                                                     >> 0x13U)));
    vlTOPp->testbench__DOT__dut__DOT__imm_b = ((0x1801U 
                                                & (IData)(vlTOPp->testbench__DOT__dut__DOT__imm_b)) 
                                               | ((0x7e0U 
                                                   & (vlTOPp->testbench__DOT__imem_data 
                                                      >> 0x14U)) 
                                                  | (0x1eU 
                                                     & (vlTOPp->testbench__DOT__imem_data 
                                                        >> 7U))));
    vlTOPp->testbench__DOT__dut__DOT__imm_b = ((0x17ffU 
                                                & (IData)(vlTOPp->testbench__DOT__dut__DOT__imm_b)) 
                                               | (0x800U 
                                                  & (vlTOPp->testbench__DOT__imem_data 
                                                     << 4U)));
    vlTOPp->testbench__DOT__dut__DOT__imm_j = ((0xfffffU 
                                                & vlTOPp->testbench__DOT__dut__DOT__imm_j) 
                                               | (0x100000U 
                                                  & (vlTOPp->testbench__DOT__imem_data 
                                                     >> 0xbU)));
    vlTOPp->testbench__DOT__dut__DOT__imm_j = ((0x1ff801U 
                                                & vlTOPp->testbench__DOT__dut__DOT__imm_j) 
                                               | (0x7feU 
                                                  & (vlTOPp->testbench__DOT__imem_data 
                                                     >> 0x14U)));
    vlTOPp->testbench__DOT__dut__DOT__imm_j = ((0x1ff7ffU 
                                                & vlTOPp->testbench__DOT__dut__DOT__imm_j) 
                                               | (0x800U 
                                                  & (vlTOPp->testbench__DOT__imem_data 
                                                     >> 9U)));
    vlTOPp->testbench__DOT__dut__DOT__imm_j = ((0x100fffU 
                                                & vlTOPp->testbench__DOT__dut__DOT__imm_j) 
                                               | (0xff000U 
                                                  & vlTOPp->testbench__DOT__imem_data));
}

VL_INLINE_OPT void Vtestbench::_combo__TOP__4(Vtestbench__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench::_combo__TOP__4\n"); );
    Vtestbench* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->testbench__DOT__dut__DOT__next_wr_stall = 0U;
    if ((1U & (((~ (IData)(vlTOPp->testbench__DOT__dut__DOT__stall_stage2)) 
                & (~ (IData)(vlTOPp->testbench__DOT__dut__DOT__kill_jmp_stage2))) 
               & (~ (IData)(vlTOPp->testbench__DOT__dut__DOT__mem_rd_enable_q))))) {
        if ((0x40U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
            if ((0x20U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                if ((1U & (~ (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                              >> 4U)))) {
                    if ((8U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                        if ((4U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                            if ((2U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                                if ((1U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                                    vlTOPp->testbench__DOT__dut__DOT__next_wr_stall = 1U;
                                }
                            }
                        }
                    } else {
                        if ((4U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                            if ((2U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                                if ((1U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                                    if ((0U == (7U 
                                                & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                   >> 0xcU)))) {
                                        vlTOPp->testbench__DOT__dut__DOT__next_wr_stall = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if ((0x20U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                if ((0x10U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                    if ((1U & (~ (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                  >> 3U)))) {
                        if ((4U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                            if ((2U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                                if ((1U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                                    vlTOPp->testbench__DOT__dut__DOT__next_wr_stall = 1U;
                                }
                            }
                        }
                    }
                }
            } else {
                if ((0x10U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                    if ((1U & (~ (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                  >> 3U)))) {
                        if ((4U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                            if ((2U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                                if ((1U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                                    vlTOPp->testbench__DOT__dut__DOT__next_wr_stall = 1U;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->testbench__DOT__dut__DOT__mem_rd_enable_q) {
        vlTOPp->testbench__DOT__dut__DOT__next_wr_stall = 0U;
    }
    if (((IData)(vlTOPp->reset) | (IData)(vlTOPp->testbench__DOT__dut__DOT__reset_q))) {
        vlTOPp->testbench__DOT__dut__DOT__next_wr_stall = 0U;
    }
    vlTOPp->testbench__DOT__dut__DOT__npc = ((IData)(vlTOPp->testbench__DOT__dut__DOT__stall)
                                              ? vlTOPp->testbench__DOT__dut__DOT__pc
                                              : ((IData)(4U) 
                                                 + vlTOPp->testbench__DOT__dut__DOT__pc));
    vlTOPp->testbench__DOT__dut__DOT__next_wr_bypass = 0U;
    vlTOPp->testbench__DOT__dut__DOT__illinsn = 0U;
    vlTOPp->testbench__DOT__dut__DOT__stall = 0U;
    vlTOPp->testbench__DOT__dut__DOT__bypass_rs1 = 0U;
    vlTOPp->testbench__DOT__dut__DOT__bypass_rs2 = 0U;
    vlTOPp->testbench__DOT__dut__DOT__re1_enable = 0U;
    vlTOPp->testbench__DOT__dut__DOT__re2_enable = 0U;
    vlTOPp->testbench__DOT__dut__DOT__mem_wr_enable = 0U;
    vlTOPp->testbench__DOT__dut__DOT__mem_wr_addr = 0U;
    vlTOPp->testbench__DOT__dut__DOT__mem_wr_data = 0U;
    vlTOPp->testbench__DOT__dut__DOT__mem_wr_strb = 0U;
    vlTOPp->testbench__DOT__dut__DOT__mem_rd_enable = 0U;
    vlTOPp->testbench__DOT__dut__DOT__mem_rd_addr = 0U;
    vlTOPp->testbench__DOT__dut__DOT__mem_rd_reg = 0U;
    vlTOPp->testbench__DOT__dut__DOT__mem_rd_func = 0U;
    if ((0x33U == (0x7fU & vlTOPp->testbench__DOT__imem_data))) {
        vlTOPp->testbench__DOT__dut__DOT__re1_enable = 1U;
        vlTOPp->testbench__DOT__dut__DOT__re2_enable = 1U;
    } else {
        if ((0x13U == (0x7fU & vlTOPp->testbench__DOT__imem_data))) {
            vlTOPp->testbench__DOT__dut__DOT__re1_enable = 1U;
        } else {
            if ((3U == (0x7fU & vlTOPp->testbench__DOT__imem_data))) {
                vlTOPp->testbench__DOT__dut__DOT__re1_enable = 1U;
            } else {
                if ((0x23U == (0x7fU & vlTOPp->testbench__DOT__imem_data))) {
                    vlTOPp->testbench__DOT__dut__DOT__re1_enable = 1U;
                    vlTOPp->testbench__DOT__dut__DOT__re2_enable = 1U;
                } else {
                    if ((0x63U == (0x7fU & vlTOPp->testbench__DOT__imem_data))) {
                        vlTOPp->testbench__DOT__dut__DOT__re1_enable = 1U;
                        vlTOPp->testbench__DOT__dut__DOT__re2_enable = 1U;
                    } else {
                        if ((0x67U == (0x7fU & vlTOPp->testbench__DOT__imem_data))) {
                            vlTOPp->testbench__DOT__dut__DOT__re1_enable = 1U;
                        } else {
                            if ((0x6fU == (0x7fU & vlTOPp->testbench__DOT__imem_data))) {
                                vlTOPp->testbench__DOT__dut__DOT__re1_enable = 0U;
                                vlTOPp->testbench__DOT__dut__DOT__re2_enable = 0U;
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (((~ (IData)(vlTOPp->testbench__DOT__dut__DOT__stall_stage2)) 
                & (~ (IData)(vlTOPp->testbench__DOT__dut__DOT__kill_jmp_stage2))) 
               & (~ (IData)(vlTOPp->testbench__DOT__dut__DOT__mem_rd_enable_q))))) {
        if ((0x40U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
            if ((0x20U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                if ((0x10U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                    vlTOPp->testbench__DOT__dut__DOT__illinsn = 1U;
                } else {
                    if ((8U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                        if ((4U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                            if ((2U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                                if ((1U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                                    vlTOPp->testbench__DOT__dut__DOT__npc 
                                        = (vlTOPp->testbench__DOT__dut__DOT__ppc 
                                           + vlTOPp->testbench__DOT__dut__DOT__imm_j_sext);
                                    if ((0U != (3U 
                                                & vlTOPp->testbench__DOT__dut__DOT__npc))) {
                                        vlTOPp->testbench__DOT__dut__DOT__npc 
                                            = (0xfffffffcU 
                                               & vlTOPp->testbench__DOT__dut__DOT__npc);
                                        vlTOPp->testbench__DOT__dut__DOT__illinsn = 1U;
                                    }
                                } else {
                                    vlTOPp->testbench__DOT__dut__DOT__illinsn = 1U;
                                }
                            } else {
                                vlTOPp->testbench__DOT__dut__DOT__illinsn = 1U;
                            }
                        } else {
                            vlTOPp->testbench__DOT__dut__DOT__illinsn = 1U;
                        }
                    } else {
                        if ((4U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                            if ((2U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                                if ((1U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                                    if ((0U == (7U 
                                                & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                   >> 0xcU)))) {
                                        vlTOPp->testbench__DOT__dut__DOT__npc 
                                            = (0xfffffffeU 
                                               & (vlTOPp->testbench__DOT__dut__DOT__rs1_value 
                                                  + vlTOPp->testbench__DOT__dut__DOT__imm_i_sext));
                                    } else {
                                        vlTOPp->testbench__DOT__dut__DOT__illinsn = 1U;
                                    }
                                    if ((0U != (3U 
                                                & vlTOPp->testbench__DOT__dut__DOT__npc))) {
                                        vlTOPp->testbench__DOT__dut__DOT__npc 
                                            = (0xfffffffcU 
                                               & vlTOPp->testbench__DOT__dut__DOT__npc);
                                        vlTOPp->testbench__DOT__dut__DOT__illinsn = 1U;
                                    }
                                } else {
                                    vlTOPp->testbench__DOT__dut__DOT__illinsn = 1U;
                                }
                            } else {
                                vlTOPp->testbench__DOT__dut__DOT__illinsn = 1U;
                            }
                        } else {
                            if ((2U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                                if ((1U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                                    if ((0x4000U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                                        if ((0x2000U 
                                             & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                                            if ((0x1000U 
                                                 & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                                                if (
                                                    (vlTOPp->testbench__DOT__dut__DOT__rs1_value 
                                                     >= vlTOPp->testbench__DOT__dut__DOT__rs2_value)) {
                                                    vlTOPp->testbench__DOT__dut__DOT__npc 
                                                        = 
                                                        (vlTOPp->testbench__DOT__dut__DOT__ppc 
                                                         + vlTOPp->testbench__DOT__dut__DOT__imm_b_sext);
                                                }
                                            } else {
                                                if (
                                                    (vlTOPp->testbench__DOT__dut__DOT__rs1_value 
                                                     < vlTOPp->testbench__DOT__dut__DOT__rs2_value)) {
                                                    vlTOPp->testbench__DOT__dut__DOT__npc 
                                                        = 
                                                        (vlTOPp->testbench__DOT__dut__DOT__ppc 
                                                         + vlTOPp->testbench__DOT__dut__DOT__imm_b_sext);
                                                }
                                            }
                                        } else {
                                            if ((0x1000U 
                                                 & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                                                if (
                                                    VL_GTES_III(1,32,32, vlTOPp->testbench__DOT__dut__DOT__rs1_value, vlTOPp->testbench__DOT__dut__DOT__rs2_value)) {
                                                    vlTOPp->testbench__DOT__dut__DOT__npc 
                                                        = 
                                                        (vlTOPp->testbench__DOT__dut__DOT__ppc 
                                                         + vlTOPp->testbench__DOT__dut__DOT__imm_b_sext);
                                                }
                                            } else {
                                                if (
                                                    VL_LTS_III(1,32,32, vlTOPp->testbench__DOT__dut__DOT__rs1_value, vlTOPp->testbench__DOT__dut__DOT__rs2_value)) {
                                                    vlTOPp->testbench__DOT__dut__DOT__npc 
                                                        = 
                                                        (vlTOPp->testbench__DOT__dut__DOT__ppc 
                                                         + vlTOPp->testbench__DOT__dut__DOT__imm_b_sext);
                                                }
                                            }
                                        }
                                    } else {
                                        if ((0x2000U 
                                             & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                                            vlTOPp->testbench__DOT__dut__DOT__illinsn = 1U;
                                        } else {
                                            if ((0x1000U 
                                                 & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                                                if (
                                                    (vlTOPp->testbench__DOT__dut__DOT__rs1_value 
                                                     != vlTOPp->testbench__DOT__dut__DOT__rs2_value)) {
                                                    vlTOPp->testbench__DOT__dut__DOT__npc 
                                                        = 
                                                        (vlTOPp->testbench__DOT__dut__DOT__ppc 
                                                         + vlTOPp->testbench__DOT__dut__DOT__imm_b_sext);
                                                }
                                            } else {
                                                if (
                                                    (vlTOPp->testbench__DOT__dut__DOT__rs1_value 
                                                     == vlTOPp->testbench__DOT__dut__DOT__rs2_value)) {
                                                    vlTOPp->testbench__DOT__dut__DOT__npc 
                                                        = 
                                                        (vlTOPp->testbench__DOT__dut__DOT__ppc 
                                                         + vlTOPp->testbench__DOT__dut__DOT__imm_b_sext);
                                                }
                                            }
                                        }
                                    }
                                    if ((0U != (3U 
                                                & vlTOPp->testbench__DOT__dut__DOT__npc))) {
                                        vlTOPp->testbench__DOT__dut__DOT__npc 
                                            = (0xfffffffcU 
                                               & vlTOPp->testbench__DOT__dut__DOT__npc);
                                        vlTOPp->testbench__DOT__dut__DOT__illinsn = 1U;
                                    }
                                } else {
                                    vlTOPp->testbench__DOT__dut__DOT__illinsn = 1U;
                                }
                            } else {
                                vlTOPp->testbench__DOT__dut__DOT__illinsn = 1U;
                            }
                        }
                    }
                }
            } else {
                vlTOPp->testbench__DOT__dut__DOT__illinsn = 1U;
            }
        } else {
            if ((0x20U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                if ((0x10U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                    if ((8U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                        vlTOPp->testbench__DOT__dut__DOT__illinsn = 1U;
                    } else {
                        if ((4U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                            if ((2U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                                if ((1U & (~ vlTOPp->testbench__DOT__dut__DOT__insn_stage2))) {
                                    vlTOPp->testbench__DOT__dut__DOT__illinsn = 1U;
                                }
                            } else {
                                vlTOPp->testbench__DOT__dut__DOT__illinsn = 1U;
                            }
                        } else {
                            if ((2U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                                if ((1U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                                    if (((((((((0U 
                                                == 
                                                ((0x3f8U 
                                                  & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                     >> 0x16U)) 
                                                 | (7U 
                                                    & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                       >> 0xcU)))) 
                                               | (0x100U 
                                                  == 
                                                  ((0x3f8U 
                                                    & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                       >> 0x16U)) 
                                                   | (7U 
                                                      & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                         >> 0xcU))))) 
                                              | (1U 
                                                 == 
                                                 ((0x3f8U 
                                                   & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                      >> 0x16U)) 
                                                  | (7U 
                                                     & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                        >> 0xcU))))) 
                                             | (2U 
                                                == 
                                                ((0x3f8U 
                                                  & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                     >> 0x16U)) 
                                                 | (7U 
                                                    & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                       >> 0xcU))))) 
                                            | (3U == 
                                               ((0x3f8U 
                                                 & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                    >> 0x16U)) 
                                                | (7U 
                                                   & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                      >> 0xcU))))) 
                                           | (4U == 
                                              ((0x3f8U 
                                                & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                   >> 0x16U)) 
                                               | (7U 
                                                  & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                     >> 0xcU))))) 
                                          | (5U == 
                                             ((0x3f8U 
                                               & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                  >> 0x16U)) 
                                              | (7U 
                                                 & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                    >> 0xcU))))) 
                                         | (0x105U 
                                            == ((0x3f8U 
                                                 & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                    >> 0x16U)) 
                                                | (7U 
                                                   & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                      >> 0xcU)))))) {
                                        vlTOPp->testbench__DOT__dut__DOT__next_wr_bypass = 1U;
                                    } else {
                                        if ((6U == 
                                             ((0x3f8U 
                                               & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                  >> 0x16U)) 
                                              | (7U 
                                                 & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                    >> 0xcU))))) {
                                            vlTOPp->testbench__DOT__dut__DOT__next_wr_bypass = 1U;
                                        } else {
                                            if ((7U 
                                                 == 
                                                 ((0x3f8U 
                                                   & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                      >> 0x16U)) 
                                                  | (7U 
                                                     & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                        >> 0xcU))))) {
                                                vlTOPp->testbench__DOT__dut__DOT__next_wr_bypass = 1U;
                                            } else {
                                                vlTOPp->testbench__DOT__dut__DOT__illinsn = 1U;
                                            }
                                        }
                                    }
                                    if (((((0x1fU & 
                                            (vlTOPp->testbench__DOT__imem_data 
                                             >> 0xfU)) 
                                           == (0x1fU 
                                               & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                  >> 7U))) 
                                          & (IData)(vlTOPp->testbench__DOT__dut__DOT__next_wr_bypass)) 
                                         & (IData)(vlTOPp->testbench__DOT__dut__DOT__re1_enable))) {
                                        vlTOPp->testbench__DOT__dut__DOT__bypass_rs1 = 1U;
                                    } else {
                                        if (((((0x1fU 
                                                & (vlTOPp->testbench__DOT__imem_data 
                                                   >> 0x14U)) 
                                               == (0x1fU 
                                                   & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                      >> 7U))) 
                                              & (IData)(vlTOPp->testbench__DOT__dut__DOT__next_wr_bypass)) 
                                             & (IData)(vlTOPp->testbench__DOT__dut__DOT__re2_enable))) {
                                            vlTOPp->testbench__DOT__dut__DOT__bypass_rs2 = 1U;
                                        }
                                    }
                                } else {
                                    vlTOPp->testbench__DOT__dut__DOT__illinsn = 1U;
                                }
                            } else {
                                vlTOPp->testbench__DOT__dut__DOT__illinsn = 1U;
                            }
                        }
                    }
                } else {
                    if ((8U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                        vlTOPp->testbench__DOT__dut__DOT__illinsn = 1U;
                    } else {
                        if ((4U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                            vlTOPp->testbench__DOT__dut__DOT__illinsn = 1U;
                        } else {
                            if ((2U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                                if ((1U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                                    vlTOPp->testbench__DOT__dut__DOT__mem_wr_addr 
                                        = (vlTOPp->testbench__DOT__dut__DOT__rs1_value 
                                           + vlTOPp->testbench__DOT__dut__DOT__imm_s_sext);
                                    if ((((0U == (0x1cU 
                                                  & ((0x1cU 
                                                      & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                         >> 0xaU)) 
                                                     | (3U 
                                                        & vlTOPp->testbench__DOT__dut__DOT__mem_wr_addr)))) 
                                          | (4U == 
                                             (0x1dU 
                                              & ((0x1cU 
                                                  & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                     >> 0xaU)) 
                                                 | (3U 
                                                    & vlTOPp->testbench__DOT__dut__DOT__mem_wr_addr))))) 
                                         | (8U == (
                                                   (0x1cU 
                                                    & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                       >> 0xaU)) 
                                                   | (3U 
                                                      & vlTOPp->testbench__DOT__dut__DOT__mem_wr_addr))))) {
                                        vlTOPp->testbench__DOT__dut__DOT__mem_wr_enable = 1U;
                                        vlTOPp->testbench__DOT__dut__DOT__mem_wr_data 
                                            = vlTOPp->testbench__DOT__dut__DOT__rs2_value;
                                        vlTOPp->testbench__DOT__dut__DOT__mem_wr_strb = 0xfU;
                                        if ((0U == 
                                             (7U & 
                                              (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                               >> 0xcU)))) {
                                            vlTOPp->testbench__DOT__dut__DOT__mem_wr_strb = 1U;
                                        } else {
                                            if ((1U 
                                                 == 
                                                 (7U 
                                                  & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                     >> 0xcU)))) {
                                                vlTOPp->testbench__DOT__dut__DOT__mem_wr_strb = 3U;
                                            } else {
                                                if (
                                                    (2U 
                                                     == 
                                                     (7U 
                                                      & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                         >> 0xcU)))) {
                                                    vlTOPp->testbench__DOT__dut__DOT__mem_wr_strb = 0xfU;
                                                }
                                            }
                                        }
                                        vlTOPp->testbench__DOT__dut__DOT__mem_wr_data 
                                            = ((0x1fU 
                                                >= 
                                                (0x18U 
                                                 & (vlTOPp->testbench__DOT__dut__DOT__mem_wr_addr 
                                                    << 3U)))
                                                ? (vlTOPp->testbench__DOT__dut__DOT__mem_wr_data 
                                                   << 
                                                   (0x18U 
                                                    & (vlTOPp->testbench__DOT__dut__DOT__mem_wr_addr 
                                                       << 3U)))
                                                : 0U);
                                        vlTOPp->testbench__DOT__dut__DOT__mem_wr_strb 
                                            = (0xfU 
                                               & ((IData)(vlTOPp->testbench__DOT__dut__DOT__mem_wr_strb) 
                                                  << 
                                                  (3U 
                                                   & vlTOPp->testbench__DOT__dut__DOT__mem_wr_addr)));
                                        vlTOPp->testbench__DOT__dut__DOT__mem_wr_addr 
                                            = (0xfffffffcU 
                                               & vlTOPp->testbench__DOT__dut__DOT__mem_wr_addr);
                                    } else {
                                        vlTOPp->testbench__DOT__dut__DOT__illinsn = 1U;
                                    }
                                } else {
                                    vlTOPp->testbench__DOT__dut__DOT__illinsn = 1U;
                                }
                            } else {
                                vlTOPp->testbench__DOT__dut__DOT__illinsn = 1U;
                            }
                        }
                    }
                }
            } else {
                if ((0x10U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                    if ((8U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                        vlTOPp->testbench__DOT__dut__DOT__illinsn = 1U;
                    } else {
                        if ((4U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                            if ((2U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                                if ((1U & (~ vlTOPp->testbench__DOT__dut__DOT__insn_stage2))) {
                                    vlTOPp->testbench__DOT__dut__DOT__illinsn = 1U;
                                }
                            } else {
                                vlTOPp->testbench__DOT__dut__DOT__illinsn = 1U;
                            }
                        } else {
                            if ((2U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                                if ((1U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                                    if (((((((((0U 
                                                == 
                                                (7U 
                                                 & ((0x3f8U 
                                                     & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                        >> 0x16U)) 
                                                    | (7U 
                                                       & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                          >> 0xcU))))) 
                                               | (2U 
                                                  == 
                                                  (7U 
                                                   & ((0x3f8U 
                                                       & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                          >> 0x16U)) 
                                                      | (7U 
                                                         & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                            >> 0xcU)))))) 
                                              | (3U 
                                                 == 
                                                 (7U 
                                                  & ((0x3f8U 
                                                      & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                         >> 0x16U)) 
                                                     | (7U 
                                                        & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                           >> 0xcU)))))) 
                                             | (4U 
                                                == 
                                                (7U 
                                                 & ((0x3f8U 
                                                     & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                        >> 0x16U)) 
                                                    | (7U 
                                                       & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                          >> 0xcU)))))) 
                                            | (6U == 
                                               (7U 
                                                & ((0x3f8U 
                                                    & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                       >> 0x16U)) 
                                                   | (7U 
                                                      & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                         >> 0xcU)))))) 
                                           | (7U == 
                                              (7U & 
                                               ((0x3f8U 
                                                 & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                    >> 0x16U)) 
                                                | (7U 
                                                   & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                      >> 0xcU)))))) 
                                          | (1U == 
                                             ((0x3f8U 
                                               & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                  >> 0x16U)) 
                                              | (7U 
                                                 & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                    >> 0xcU))))) 
                                         | (5U == (
                                                   (0x3f8U 
                                                    & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                       >> 0x16U)) 
                                                   | (7U 
                                                      & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                         >> 0xcU)))))) {
                                        vlTOPp->testbench__DOT__dut__DOT__next_wr_bypass = 1U;
                                    } else {
                                        if ((0x105U 
                                             == ((0x3f8U 
                                                  & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                     >> 0x16U)) 
                                                 | (7U 
                                                    & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                       >> 0xcU))))) {
                                            vlTOPp->testbench__DOT__dut__DOT__next_wr_bypass = 1U;
                                        } else {
                                            vlTOPp->testbench__DOT__dut__DOT__illinsn = 1U;
                                        }
                                    }
                                    if (((((0x1fU & 
                                            (vlTOPp->testbench__DOT__imem_data 
                                             >> 0xfU)) 
                                           == (0x1fU 
                                               & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                  >> 7U))) 
                                          & (IData)(vlTOPp->testbench__DOT__dut__DOT__next_wr_bypass)) 
                                         & (IData)(vlTOPp->testbench__DOT__dut__DOT__re1_enable))) {
                                        vlTOPp->testbench__DOT__dut__DOT__bypass_rs1 = 1U;
                                    } else {
                                        if (((((0x1fU 
                                                & (vlTOPp->testbench__DOT__imem_data 
                                                   >> 0x14U)) 
                                               == (0x1fU 
                                                   & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                      >> 7U))) 
                                              & (IData)(vlTOPp->testbench__DOT__dut__DOT__next_wr_bypass)) 
                                             & (IData)(vlTOPp->testbench__DOT__dut__DOT__re2_enable))) {
                                            vlTOPp->testbench__DOT__dut__DOT__bypass_rs2 = 1U;
                                        }
                                    }
                                } else {
                                    vlTOPp->testbench__DOT__dut__DOT__illinsn = 1U;
                                }
                            } else {
                                vlTOPp->testbench__DOT__dut__DOT__illinsn = 1U;
                            }
                        }
                    }
                } else {
                    if ((8U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                        vlTOPp->testbench__DOT__dut__DOT__illinsn = 1U;
                    } else {
                        if ((4U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                            vlTOPp->testbench__DOT__dut__DOT__illinsn = 1U;
                        } else {
                            if ((2U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                                if ((1U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                                    vlTOPp->testbench__DOT__dut__DOT__mem_rd_addr 
                                        = (vlTOPp->testbench__DOT__dut__DOT__rs1_value 
                                           + vlTOPp->testbench__DOT__dut__DOT__imm_i_sext);
                                    vlTOPp->testbench__DOT__dut__DOT__npc 
                                        = vlTOPp->testbench__DOT__dut__DOT__pc;
                                    if (((((0x1fU & 
                                            (vlTOPp->testbench__DOT__imem_data 
                                             >> 0xfU)) 
                                           == (0x1fU 
                                               & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                  >> 7U))) 
                                          & (IData)(vlTOPp->testbench__DOT__dut__DOT__re1_enable)) 
                                         | (((0x1fU 
                                              & (vlTOPp->testbench__DOT__imem_data 
                                                 >> 0x14U)) 
                                             == (0x1fU 
                                                 & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                    >> 7U))) 
                                            & (IData)(vlTOPp->testbench__DOT__dut__DOT__re2_enable)))) {
                                        vlTOPp->testbench__DOT__dut__DOT__stall = 1U;
                                    }
                                    if ((0x4000U & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                                        if ((0x2000U 
                                             & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                                            vlTOPp->testbench__DOT__dut__DOT__illinsn = 1U;
                                        } else {
                                            if ((0x1000U 
                                                 & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                                                if (
                                                    (1U 
                                                     & vlTOPp->testbench__DOT__dut__DOT__mem_rd_addr)) {
                                                    vlTOPp->testbench__DOT__dut__DOT__illinsn = 1U;
                                                } else {
                                                    vlTOPp->testbench__DOT__dut__DOT__mem_rd_enable = 1U;
                                                    vlTOPp->testbench__DOT__dut__DOT__mem_rd_reg 
                                                        = 
                                                        (0x1fU 
                                                         & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                            >> 7U));
                                                    vlTOPp->testbench__DOT__dut__DOT__mem_rd_func 
                                                        = 
                                                        ((0x18U 
                                                          & (vlTOPp->testbench__DOT__dut__DOT__mem_rd_addr 
                                                             << 3U)) 
                                                         | (7U 
                                                            & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                               >> 0xcU)));
                                                    vlTOPp->testbench__DOT__dut__DOT__mem_rd_addr 
                                                        = 
                                                        (0xfffffffcU 
                                                         & vlTOPp->testbench__DOT__dut__DOT__mem_rd_addr);
                                                }
                                            } else {
                                                vlTOPp->testbench__DOT__dut__DOT__mem_rd_enable = 1U;
                                                vlTOPp->testbench__DOT__dut__DOT__mem_rd_reg 
                                                    = 
                                                    (0x1fU 
                                                     & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                        >> 7U));
                                                vlTOPp->testbench__DOT__dut__DOT__mem_rd_func 
                                                    = 
                                                    ((0x18U 
                                                      & (vlTOPp->testbench__DOT__dut__DOT__mem_rd_addr 
                                                         << 3U)) 
                                                     | (7U 
                                                        & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                           >> 0xcU)));
                                                vlTOPp->testbench__DOT__dut__DOT__mem_rd_addr 
                                                    = 
                                                    (0xfffffffcU 
                                                     & vlTOPp->testbench__DOT__dut__DOT__mem_rd_addr);
                                            }
                                        }
                                    } else {
                                        if ((0x2000U 
                                             & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                                            if ((0x1000U 
                                                 & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                                                vlTOPp->testbench__DOT__dut__DOT__illinsn = 1U;
                                            } else {
                                                if (
                                                    (2U 
                                                     & vlTOPp->testbench__DOT__dut__DOT__mem_rd_addr)) {
                                                    vlTOPp->testbench__DOT__dut__DOT__illinsn = 1U;
                                                } else {
                                                    if (
                                                        (1U 
                                                         & vlTOPp->testbench__DOT__dut__DOT__mem_rd_addr)) {
                                                        vlTOPp->testbench__DOT__dut__DOT__illinsn = 1U;
                                                    } else {
                                                        vlTOPp->testbench__DOT__dut__DOT__mem_rd_enable = 1U;
                                                        vlTOPp->testbench__DOT__dut__DOT__mem_rd_reg 
                                                            = 
                                                            (0x1fU 
                                                             & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                                >> 7U));
                                                        vlTOPp->testbench__DOT__dut__DOT__mem_rd_func 
                                                            = 
                                                            ((0x18U 
                                                              & (vlTOPp->testbench__DOT__dut__DOT__mem_rd_addr 
                                                                 << 3U)) 
                                                             | (7U 
                                                                & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                                   >> 0xcU)));
                                                        vlTOPp->testbench__DOT__dut__DOT__mem_rd_addr 
                                                            = 
                                                            (0xfffffffcU 
                                                             & vlTOPp->testbench__DOT__dut__DOT__mem_rd_addr);
                                                    }
                                                }
                                            }
                                        } else {
                                            if ((0x1000U 
                                                 & vlTOPp->testbench__DOT__dut__DOT__insn_stage2)) {
                                                if (
                                                    (1U 
                                                     & vlTOPp->testbench__DOT__dut__DOT__mem_rd_addr)) {
                                                    vlTOPp->testbench__DOT__dut__DOT__illinsn = 1U;
                                                } else {
                                                    vlTOPp->testbench__DOT__dut__DOT__mem_rd_enable = 1U;
                                                    vlTOPp->testbench__DOT__dut__DOT__mem_rd_reg 
                                                        = 
                                                        (0x1fU 
                                                         & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                            >> 7U));
                                                    vlTOPp->testbench__DOT__dut__DOT__mem_rd_func 
                                                        = 
                                                        ((0x18U 
                                                          & (vlTOPp->testbench__DOT__dut__DOT__mem_rd_addr 
                                                             << 3U)) 
                                                         | (7U 
                                                            & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                               >> 0xcU)));
                                                    vlTOPp->testbench__DOT__dut__DOT__mem_rd_addr 
                                                        = 
                                                        (0xfffffffcU 
                                                         & vlTOPp->testbench__DOT__dut__DOT__mem_rd_addr);
                                                }
                                            } else {
                                                vlTOPp->testbench__DOT__dut__DOT__mem_rd_enable = 1U;
                                                vlTOPp->testbench__DOT__dut__DOT__mem_rd_reg 
                                                    = 
                                                    (0x1fU 
                                                     & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                        >> 7U));
                                                vlTOPp->testbench__DOT__dut__DOT__mem_rd_func 
                                                    = 
                                                    ((0x18U 
                                                      & (vlTOPp->testbench__DOT__dut__DOT__mem_rd_addr 
                                                         << 3U)) 
                                                     | (7U 
                                                        & (vlTOPp->testbench__DOT__dut__DOT__insn_stage2 
                                                           >> 0xcU)));
                                                vlTOPp->testbench__DOT__dut__DOT__mem_rd_addr 
                                                    = 
                                                    (0xfffffffcU 
                                                     & vlTOPp->testbench__DOT__dut__DOT__mem_rd_addr);
                                            }
                                        }
                                    }
                                } else {
                                    vlTOPp->testbench__DOT__dut__DOT__illinsn = 1U;
                                }
                            } else {
                                vlTOPp->testbench__DOT__dut__DOT__illinsn = 1U;
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->testbench__DOT__dut__DOT__mem_rd_enable_q) {
        vlTOPp->testbench__DOT__dut__DOT__npc = vlTOPp->testbench__DOT__dut__DOT__pc;
        vlTOPp->testbench__DOT__dut__DOT__illinsn = 0U;
        vlTOPp->testbench__DOT__dut__DOT__mem_rd_enable = 0U;
        vlTOPp->testbench__DOT__dut__DOT__mem_wr_enable = 0U;
    }
    if (((IData)(vlTOPp->reset) | (IData)(vlTOPp->testbench__DOT__dut__DOT__reset_q))) {
        vlTOPp->testbench__DOT__dut__DOT__npc = 0U;
        vlTOPp->testbench__DOT__dut__DOT__next_wr_bypass = 0U;
        vlTOPp->testbench__DOT__dut__DOT__illinsn = 0U;
        vlTOPp->testbench__DOT__dut__DOT__mem_rd_enable = 0U;
        vlTOPp->testbench__DOT__dut__DOT__mem_wr_enable = 0U;
    }
    vlTOPp->testbench__DOT__imem_addr = ((((IData)(vlTOPp->testbench__DOT__dut__DOT__trapped) 
                                           | (IData)(vlTOPp->testbench__DOT__dut__DOT__stall)) 
                                          | (IData)(vlTOPp->testbench__DOT__dut__DOT__mem_rd_enable_q))
                                          ? vlTOPp->testbench__DOT__dut__DOT__imem_addr_q
                                          : vlTOPp->testbench__DOT__dut__DOT__npc);
    vlTOPp->testbench__DOT__dmem_valid = ((IData)(vlTOPp->testbench__DOT__dut__DOT__mem_wr_enable) 
                                          | (IData)(vlTOPp->testbench__DOT__dut__DOT__mem_rd_enable));
    if (vlTOPp->testbench__DOT__dut__DOT__mem_wr_enable) {
        vlTOPp->testbench__DOT__dmem_wstrb = vlTOPp->testbench__DOT__dut__DOT__mem_wr_strb;
        vlTOPp->testbench__DOT__dmem_wdata = vlTOPp->testbench__DOT__dut__DOT__mem_wr_data;
        vlTOPp->testbench__DOT__dmem_addr = vlTOPp->testbench__DOT__dut__DOT__mem_wr_addr;
    } else {
        vlTOPp->testbench__DOT__dmem_wstrb = 0U;
        vlTOPp->testbench__DOT__dmem_wdata = 0U;
        vlTOPp->testbench__DOT__dmem_addr = ((IData)(vlTOPp->testbench__DOT__dut__DOT__mem_rd_enable)
                                              ? vlTOPp->testbench__DOT__dut__DOT__mem_rd_addr
                                              : 0U);
    }
}

void Vtestbench::_eval(Vtestbench__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench::_eval\n"); );
    Vtestbench* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
    }
    vlTOPp->_combo__TOP__4(vlSymsp);
    vlTOPp->__Vm_traceActivity[2U] = 1U;
    // Final
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

VL_INLINE_OPT QData Vtestbench::_change_request(Vtestbench__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench::_change_request\n"); );
    Vtestbench* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vtestbench::_change_request_1(Vtestbench__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench::_change_request_1\n"); );
    Vtestbench* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlTOPp->testbench__DOT__dut__DOT__stall ^ vlTOPp->__Vchglast__TOP__testbench__DOT__dut__DOT__stall));
    VL_DEBUG_IF( if(__req && ((vlTOPp->testbench__DOT__dut__DOT__stall ^ vlTOPp->__Vchglast__TOP__testbench__DOT__dut__DOT__stall))) VL_DBG_MSGF("        CHANGE: nerv.sv:215: testbench.dut.stall\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__testbench__DOT__dut__DOT__stall 
        = vlTOPp->testbench__DOT__dut__DOT__stall;
    return __req;
}

#ifdef VL_DEBUG
void Vtestbench::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG
