//===-- RISCVInstrInfoD.td - RISC-V 'D' instructions -------*- tablegen -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file describes the RISC-V instructions from the standard 'D',
// Double-Precision Floating-Point instruction set extension.
//
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
// RISC-V specific DAG Nodes.
//===----------------------------------------------------------------------===//

def SDT_RISCVBuildPairF64 : SDTypeProfile<1, 2, [SDTCisVT<0, f64>,
                                                 SDTCisVT<1, i32>,
                                                 SDTCisSameAs<1, 2>]>;
def SDT_RISCVSplitF64     : SDTypeProfile<2, 1, [SDTCisVT<0, i32>,
                                                 SDTCisVT<1, i32>,
                                                 SDTCisVT<2, f64>]>;

def RISCVBuildPairF64 : SDNode<"RISCVISD::BuildPairF64", SDT_RISCVBuildPairF64>;
def RISCVSplitF64     : SDNode<"RISCVISD::SplitF64", SDT_RISCVSplitF64>;

def AddrRegImmINX : ComplexPattern<iPTR, 2, "SelectAddrRegImmINX">;

//===----------------------------------------------------------------------===//
// Operand and SDNode transformation definitions.
//===----------------------------------------------------------------------===//

// Zdinx

def GPRPF64AsFPR : AsmOperandClass {
  let Name = "GPRPF64AsFPR";
  let ParserMethod = "parseGPRAsFPR";
  let RenderMethod = "addRegOperands";
}

def GPRF64AsFPR : AsmOperandClass {
  let Name = "GPRF64AsFPR";
  let ParserMethod = "parseGPRAsFPR";
  let RenderMethod = "addRegOperands";
}

def FPR64INX : RegisterOperand<GPRF64> {
  let ParserMatchClass = GPRF64AsFPR;
  let DecoderMethod = "DecodeGPRRegisterClass";
}

def FPR64IN32X : RegisterOperand<GPRPF64> {
  let ParserMatchClass = GPRPF64AsFPR;
}

def DExt       : ExtInfo<0, [HasStdExtD]>;
def D64Ext     : ExtInfo<0, [HasStdExtD, IsRV64]>;
def ZdinxExt   : ExtInfo<1, [HasStdExtZdinx, IsRV64]>;
def Zdinx32Ext : ExtInfo<2, [HasStdExtZdinx, IsRV32]>;

def D       : ExtInfo_r<DExt,       FPR64>;
def D_INX   : ExtInfo_r<ZdinxExt,   FPR64INX>;
def D_IN32X : ExtInfo_r<Zdinx32Ext, FPR64IN32X>;

def DD       : ExtInfo_rr<DExt,       FPR64,      FPR64>;
def DD_INX   : ExtInfo_rr<ZdinxExt,   FPR64INX,   FPR64INX>;
def DD_IN32X : ExtInfo_rr<Zdinx32Ext, FPR64IN32X, FPR64IN32X>;
def DF       : ExtInfo_rr<DExt,       FPR64,      FPR32>;
def DF_INX   : ExtInfo_rr<ZdinxExt,   FPR64INX,   FPR32INX>;
def DF_IN32X : ExtInfo_rr<Zdinx32Ext, FPR64IN32X, FPR32INX>;
def DX       : ExtInfo_rr<DExt,       FPR64,      GPR>;
def DX_INX   : ExtInfo_rr<ZdinxExt,   FPR64INX,   GPR>;
def DX_IN32X : ExtInfo_rr<Zdinx32Ext, FPR64IN32X, GPR>;
def DX_64    : ExtInfo_rr<D64Ext,     FPR64,      GPR>;
def FD       : ExtInfo_rr<DExt,       FPR32,      FPR64>;
def FD_INX   : ExtInfo_rr<ZdinxExt,   FPR32INX,   FPR64INX>;
def FD_IN32X : ExtInfo_rr<Zdinx32Ext, FPR32INX,   FPR64IN32X>;
def XD       : ExtInfo_rr<DExt,       GPR,        FPR64>;
def XD_INX   : ExtInfo_rr<ZdinxExt,   GPR,        FPR64INX>;
def XD_IN32X : ExtInfo_rr<Zdinx32Ext, GPR,        FPR64IN32X>;
def XD_64    : ExtInfo_rr<D64Ext,     GPR,        FPR64>;

defvar DINX    = [D,     D_INX,  D_IN32X];
defvar DDINX   = [DD,    DD_INX, DD_IN32X];
defvar DXINX   = [DX,    DX_INX, DX_IN32X];
defvar DFINX   = [DF,    DF_INX, DF_IN32X];
defvar FDINX   = [FD,    FD_INX, FD_IN32X];
defvar XDINX   = [XD,    XD_INX, XD_IN32X];
defvar DXIN64X = [DX_64, DX_INX];
defvar XDIN64X = [XD_64, XD_INX];

//===----------------------------------------------------------------------===//
// Instructions
//===----------------------------------------------------------------------===//

let Predicates = [HasStdExtD] in {
def FLD : FPLoad_r<0b011, "fld", FPR64, WriteFLD64>;

// Operands for stores are in the order srcreg, base, offset rather than
// reflecting the order these fields are specified in the instruction
// encoding.
def FSD : FPStore_r<0b011, "fsd", FPR64, WriteFST64>;
} // Predicates = [HasStdExtD]

let SchedRW = [WriteFMA64, ReadFMA64, ReadFMA64, ReadFMA64] in {
defm FMADD_D  : FPFMA_rrr_frm_m<OPC_MADD,  0b01, "fmadd.d",  DINX>;
defm FMSUB_D  : FPFMA_rrr_frm_m<OPC_MSUB,  0b01, "fmsub.d",  DINX>;
defm FNMSUB_D : FPFMA_rrr_frm_m<OPC_NMSUB, 0b01, "fnmsub.d", DINX>;
defm FNMADD_D : FPFMA_rrr_frm_m<OPC_NMADD, 0b01, "fnmadd.d", DINX>;
}

let SchedRW = [WriteFAdd64, ReadFAdd64, ReadFAdd64] in {
defm FADD_D : FPALU_rr_frm_m<0b0000001, "fadd.d", DINX, /*Commutable*/1>;
defm FSUB_D : FPALU_rr_frm_m<0b0000101, "fsub.d", DINX>;
}
let SchedRW = [WriteFMul64, ReadFMul64, ReadFMul64] in
defm FMUL_D : FPALU_rr_frm_m<0b0001001, "fmul.d", DINX, /*Commutable*/1>;

let SchedRW = [WriteFDiv64, ReadFDiv64, ReadFDiv64] in
defm FDIV_D : FPALU_rr_frm_m<0b0001101, "fdiv.d", DINX>;

defm FSQRT_D : FPUnaryOp_r_frm_m<0b0101101, 0b00000, DDINX, "fsqrt.d">,
               Sched<[WriteFSqrt64, ReadFSqrt64]>;

let SchedRW = [WriteFSGNJ64, ReadFSGNJ64, ReadFSGNJ64],
    mayRaiseFPException = 0 in {
defm FSGNJ_D  : FPALU_rr_m<0b0010001, 0b000, "fsgnj.d",  DINX>;
defm FSGNJN_D : FPALU_rr_m<0b0010001, 0b001, "fsgnjn.d", DINX>;
defm FSGNJX_D : FPALU_rr_m<0b0010001, 0b010, "fsgnjx.d", DINX>;
}

let SchedRW = [WriteFMinMax64, ReadFMinMax64, ReadFMinMax64] in {
defm FMIN_D   : FPALU_rr_m<0b0010101, 0b000, "fmin.d", DINX, /*Commutable*/1>;
defm FMAX_D   : FPALU_rr_m<0b0010101, 0b001, "fmax.d", DINX, /*Commutable*/1>;
}

defm FCVT_S_D : FPUnaryOp_r_frm_m<0b0100000, 0b00001, FDINX, "fcvt.s.d">,
                Sched<[WriteFCvtF64ToF32, ReadFCvtF64ToF32]>;

defm FCVT_D_S : FPUnaryOp_r_m<0b0100001, 0b00000, 0b000, DFINX, "fcvt.d.s">,
                Sched<[WriteFCvtF32ToF64, ReadFCvtF32ToF64]>;

let SchedRW = [WriteFCmp64, ReadFCmp64, ReadFCmp64] in {
defm FEQ_D : FPCmp_rr_m<0b1010001, 0b010, "feq.d", DINX, /*Commutable*/1>;
defm FLT_D : FPCmp_rr_m<0b1010001, 0b001, "flt.d", DINX>;
defm FLE_D : FPCmp_rr_m<0b1010001, 0b000, "fle.d", DINX>;
}

let mayRaiseFPException = 0 in
defm FCLASS_D : FPUnaryOp_r_m<0b1110001, 0b00000, 0b001, XDINX, "fclass.d">,
                Sched<[WriteFClass64, ReadFClass64]>;

let IsSignExtendingOpW = 1 in
defm FCVT_W_D : FPUnaryOp_r_frm_m<0b1100001, 0b00000, XDINX, "fcvt.w.d">,
               Sched<[WriteFCvtF64ToI32, ReadFCvtF64ToI32]>;

let IsSignExtendingOpW = 1 in
defm FCVT_WU_D : FPUnaryOp_r_frm_m<0b1100001, 0b00001, XDINX, "fcvt.wu.d">,
                 Sched<[WriteFCvtF64ToI32, ReadFCvtF64ToI32]>;

defm FCVT_D_W : FPUnaryOp_r_m<0b1101001, 0b00000, 0b000, DXINX, "fcvt.d.w">,
                Sched<[WriteFCvtI32ToF64, ReadFCvtI32ToF64]>;

defm FCVT_D_WU : FPUnaryOp_r_m<0b1101001, 0b00001, 0b000, DXINX, "fcvt.d.wu">,
                 Sched<[WriteFCvtI32ToF64, ReadFCvtI32ToF64]>;

defm FCVT_L_D : FPUnaryOp_r_frm_m<0b1100001, 0b00010, XDIN64X, "fcvt.l.d">,
                Sched<[WriteFCvtF64ToI64, ReadFCvtF64ToI64]>;

defm FCVT_LU_D : FPUnaryOp_r_frm_m<0b1100001, 0b00011, XDIN64X, "fcvt.lu.d">,
                 Sched<[WriteFCvtF64ToI64, ReadFCvtF64ToI64]>;

let Predicates = [HasStdExtD, IsRV64], mayRaiseFPException = 0 in
def FMV_X_D : FPUnaryOp_r<0b1110001, 0b00000, 0b000, GPR, FPR64, "fmv.x.d">,
              Sched<[WriteFMovF64ToI64, ReadFMovF64ToI64]>;

defm FCVT_D_L : FPUnaryOp_r_frm_m<0b1101001, 0b00010, DXIN64X, "fcvt.d.l">,
                Sched<[WriteFCvtI64ToF64, ReadFCvtI64ToF64]>;

defm FCVT_D_LU : FPUnaryOp_r_frm_m<0b1101001, 0b00011, DXIN64X, "fcvt.d.lu">,
                 Sched<[WriteFCvtI64ToF64, ReadFCvtI64ToF64]>;

let Predicates = [HasStdExtD, IsRV64], mayRaiseFPException = 0 in
def FMV_D_X : FPUnaryOp_r<0b1111001, 0b00000, 0b000, FPR64, GPR, "fmv.d.x">,
              Sched<[WriteFMovI64ToF64, ReadFMovI64ToF64]>;

//===----------------------------------------------------------------------===//
// Assembler Pseudo Instructions (User-Level ISA, Version 2.2, Chapter 20)
//===----------------------------------------------------------------------===//

let Predicates = [HasStdExtD] in {
def : InstAlias<"fld $rd, (${rs1})",  (FLD FPR64:$rd,  GPR:$rs1, 0), 0>;
def : InstAlias<"fsd $rs2, (${rs1})", (FSD FPR64:$rs2, GPR:$rs1, 0), 0>;

def : InstAlias<"fmv.d $rd, $rs",  (FSGNJ_D  FPR64:$rd, FPR64:$rs, FPR64:$rs)>;
def : InstAlias<"fabs.d $rd, $rs", (FSGNJX_D FPR64:$rd, FPR64:$rs, FPR64:$rs)>;
def : InstAlias<"fneg.d $rd, $rs", (FSGNJN_D FPR64:$rd, FPR64:$rs, FPR64:$rs)>;

// fgt.d/fge.d are recognised by the GNU assembler but the canonical
// flt.d/fle.d forms will always be printed. Therefore, set a zero weight.
def : InstAlias<"fgt.d $rd, $rs, $rt",
                (FLT_D GPR:$rd, FPR64:$rt, FPR64:$rs), 0>;
def : InstAlias<"fge.d $rd, $rs, $rt",
                (FLE_D GPR:$rd, FPR64:$rt, FPR64:$rs), 0>;

def PseudoFLD  : PseudoFloatLoad<"fld", FPR64>;
def PseudoFSD  : PseudoStore<"fsd", FPR64>;
let usesCustomInserter = 1 in {
def PseudoQuietFLE_D : PseudoQuietFCMP<FPR64>;
def PseudoQuietFLT_D : PseudoQuietFCMP<FPR64>;
}
} // Predicates = [HasStdExtD]

let Predicates = [HasStdExtZdinx, IsRV64] in {
def : InstAlias<"fabs.d $rd, $rs", (FSGNJX_D_INX FPR64INX:$rd, FPR64INX:$rs, FPR64INX:$rs)>;
def : InstAlias<"fneg.d $rd, $rs", (FSGNJN_D_INX FPR64INX:$rd, FPR64INX:$rs, FPR64INX:$rs)>;

def : InstAlias<"fgt.d $rd, $rs, $rt",
                (FLT_D_INX GPR:$rd, FPR64INX:$rt, FPR64INX:$rs), 0>;
def : InstAlias<"fge.d $rd, $rs, $rt",
                (FLE_D_INX GPR:$rd, FPR64INX:$rt, FPR64INX:$rs), 0>;
let usesCustomInserter = 1 in {
def PseudoQuietFLE_D_INX : PseudoQuietFCMP<FPR64INX>;
def PseudoQuietFLT_D_INX : PseudoQuietFCMP<FPR64INX>;
}
} // Predicates = [HasStdExtZdinx, IsRV64]

let Predicates = [HasStdExtZdinx, IsRV32] in {
def : InstAlias<"fabs.d $rd, $rs", (FSGNJX_D_IN32X FPR64IN32X:$rd, FPR64IN32X:$rs, FPR64IN32X:$rs)>;
def : InstAlias<"fneg.d $rd, $rs", (FSGNJN_D_IN32X FPR64IN32X:$rd, FPR64IN32X:$rs, FPR64IN32X:$rs)>;

def : InstAlias<"fgt.d $rd, $rs, $rt",
                (FLT_D_IN32X GPR:$rd, FPR64IN32X:$rt, FPR64IN32X:$rs), 0>;
def : InstAlias<"fge.d $rd, $rs, $rt",
                (FLE_D_IN32X GPR:$rd, FPR64IN32X:$rt, FPR64IN32X:$rs), 0>;
let usesCustomInserter = 1 in {
def PseudoQuietFLE_D_IN32X : PseudoQuietFCMP<FPR64IN32X>;
def PseudoQuietFLT_D_IN32X : PseudoQuietFCMP<FPR64IN32X>;
}
} // Predicates = [HasStdExtZdinx, IsRV32]

//===----------------------------------------------------------------------===//
// Pseudo-instructions and codegen patterns
//===----------------------------------------------------------------------===//

let Predicates = [HasStdExtD] in {

/// Float conversion operations

// f64 -> f32, f32 -> f64
def : Pat<(any_fpround FPR64:$rs1), (FCVT_S_D FPR64:$rs1, FRM_DYN)>;
def : Pat<(any_fpextend FPR32:$rs1), (FCVT_D_S FPR32:$rs1)>;
} // Predicates = [HasStdExtD]

let Predicates = [HasStdExtZdinx, IsRV64] in {
/// Float conversion operations

// f64 -> f32, f32 -> f64
def : Pat<(any_fpround FPR64INX:$rs1), (FCVT_S_D_INX FPR64INX:$rs1, FRM_DYN)>;
def : Pat<(any_fpextend FPR32INX:$rs1), (FCVT_D_S_INX FPR32INX:$rs1)>;
} // Predicates = [HasStdExtZdinx, IsRV64]

let Predicates = [HasStdExtZdinx, IsRV32] in {
/// Float conversion operations

// f64 -> f32, f32 -> f64
def : Pat<(any_fpround FPR64IN32X:$rs1), (FCVT_S_D_IN32X FPR64IN32X:$rs1, FRM_DYN)>;
def : Pat<(any_fpextend FPR32INX:$rs1), (FCVT_D_S_IN32X FPR32INX:$rs1)>;
} // Predicates = [HasStdExtZdinx, IsRV32]

// [u]int<->double conversion patterns must be gated on IsRV32 or IsRV64, so
// are defined later.

/// Float arithmetic operations

defm : PatFprFprDynFrm_m<any_fadd, FADD_D, DINX>;
defm : PatFprFprDynFrm_m<any_fsub, FSUB_D, DINX>;
defm : PatFprFprDynFrm_m<any_fmul, FMUL_D, DINX>;
defm : PatFprFprDynFrm_m<any_fdiv, FDIV_D, DINX>;

let Predicates = [HasStdExtD] in {
def : Pat<(any_fsqrt FPR64:$rs1), (FSQRT_D FPR64:$rs1, FRM_DYN)>;

def : Pat<(fneg FPR64:$rs1), (FSGNJN_D $rs1, $rs1)>;
def : Pat<(fabs FPR64:$rs1), (FSGNJX_D $rs1, $rs1)>;

def : Pat<(riscv_fpclass FPR64:$rs1), (FCLASS_D $rs1)>;

def : PatFprFpr<fcopysign, FSGNJ_D, FPR64>;
def : Pat<(fcopysign FPR64:$rs1, (fneg FPR64:$rs2)), (FSGNJN_D $rs1, $rs2)>;
def : Pat<(fcopysign FPR64:$rs1, FPR32:$rs2), (FSGNJ_D $rs1, (FCVT_D_S $rs2))>;
def : Pat<(fcopysign FPR32:$rs1, FPR64:$rs2), (FSGNJ_S $rs1, (FCVT_S_D $rs2,
                                                              FRM_DYN))>;

// fmadd: rs1 * rs2 + rs3
def : Pat<(any_fma FPR64:$rs1, FPR64:$rs2, FPR64:$rs3),
          (FMADD_D $rs1, $rs2, $rs3, FRM_DYN)>;

// fmsub: rs1 * rs2 - rs3
def : Pat<(any_fma FPR64:$rs1, FPR64:$rs2, (fneg FPR64:$rs3)),
          (FMSUB_D FPR64:$rs1, FPR64:$rs2, FPR64:$rs3, FRM_DYN)>;

// fnmsub: -rs1 * rs2 + rs3
def : Pat<(any_fma (fneg FPR64:$rs1), FPR64:$rs2, FPR64:$rs3),
          (FNMSUB_D FPR64:$rs1, FPR64:$rs2, FPR64:$rs3, FRM_DYN)>;

// fnmadd: -rs1 * rs2 - rs3
def : Pat<(any_fma (fneg FPR64:$rs1), FPR64:$rs2, (fneg FPR64:$rs3)),
          (FNMADD_D FPR64:$rs1, FPR64:$rs2, FPR64:$rs3, FRM_DYN)>;

// fnmadd: -(rs1 * rs2 + rs3) (the nsz flag on the FMA)
def : Pat<(fneg (any_fma_nsz FPR64:$rs1, FPR64:$rs2, FPR64:$rs3)),
          (FNMADD_D FPR64:$rs1, FPR64:$rs2, FPR64:$rs3, FRM_DYN)>;
} // Predicates = [HasStdExtD]

let Predicates = [HasStdExtZdinx, IsRV64] in {
def : Pat<(any_fsqrt FPR64INX:$rs1), (FSQRT_D_INX FPR64INX:$rs1, FRM_DYN)>;

def : Pat<(fneg FPR64INX:$rs1), (FSGNJN_D_INX $rs1, $rs1)>;
def : Pat<(fabs FPR64INX:$rs1), (FSGNJX_D_INX $rs1, $rs1)>;

def : Pat<(riscv_fpclass FPR64INX:$rs1), (FCLASS_D_INX $rs1)>;

def : PatFprFpr<fcopysign, FSGNJ_D_INX, FPR64INX>;
def : Pat<(fcopysign FPR64INX:$rs1, (fneg FPR64INX:$rs2)),
          (FSGNJN_D_INX $rs1, $rs2)>;
def : Pat<(fcopysign FPR64INX:$rs1, FPR32INX:$rs2),
          (FSGNJ_D_INX $rs1, (FCVT_D_S_INX $rs2))>;
def : Pat<(fcopysign FPR32INX:$rs1, FPR64INX:$rs2),
          (FSGNJ_S_INX $rs1, (FCVT_S_D_INX $rs2, FRM_DYN))>;

// fmadd: rs1 * rs2 + rs3
def : Pat<(any_fma FPR64INX:$rs1, FPR64INX:$rs2, FPR64INX:$rs3),
          (FMADD_D_INX $rs1, $rs2, $rs3, FRM_DYN)>;

// fmsub: rs1 * rs2 - rs3
def : Pat<(any_fma FPR64INX:$rs1, FPR64INX:$rs2, (fneg FPR64INX:$rs3)),
          (FMSUB_D_INX FPR64INX:$rs1, FPR64INX:$rs2, FPR64INX:$rs3, FRM_DYN)>;

// fnmsub: -rs1 * rs2 + rs3
def : Pat<(any_fma (fneg FPR64INX:$rs1), FPR64INX:$rs2, FPR64INX:$rs3),
          (FNMSUB_D_INX FPR64INX:$rs1, FPR64INX:$rs2, FPR64INX:$rs3, FRM_DYN)>;

// fnmadd: -rs1 * rs2 - rs3
def : Pat<(any_fma (fneg FPR64INX:$rs1), FPR64INX:$rs2, (fneg FPR64INX:$rs3)),
          (FNMADD_D_INX FPR64INX:$rs1, FPR64INX:$rs2, FPR64INX:$rs3, FRM_DYN)>;

// fnmadd: -(rs1 * rs2 + rs3) (the nsz flag on the FMA)
def : Pat<(fneg (any_fma_nsz FPR64INX:$rs1, FPR64INX:$rs2, FPR64INX:$rs3)),
          (FNMADD_D_INX FPR64INX:$rs1, FPR64INX:$rs2, FPR64INX:$rs3, FRM_DYN)>;
} // Predicates = [HasStdExtZdinx, IsRV64]

let Predicates = [HasStdExtZdinx, IsRV32] in {
def : Pat<(any_fsqrt FPR64IN32X:$rs1), (FSQRT_D_IN32X FPR64IN32X:$rs1, FRM_DYN)>;

def : Pat<(fneg FPR64IN32X:$rs1), (FSGNJN_D_IN32X $rs1, $rs1)>;
def : Pat<(fabs FPR64IN32X:$rs1), (FSGNJX_D_IN32X $rs1, $rs1)>;

def : Pat<(riscv_fpclass FPR64IN32X:$rs1), (FCLASS_D_IN32X $rs1)>;

def : PatFprFpr<fcopysign, FSGNJ_D_IN32X, FPR64IN32X>;
def : Pat<(fcopysign FPR64IN32X:$rs1, (fneg FPR64IN32X:$rs2)),
          (FSGNJN_D_IN32X $rs1, $rs2)>;
def : Pat<(fcopysign FPR64IN32X:$rs1, FPR32INX:$rs2),
          (FSGNJ_D_IN32X $rs1, (FCVT_D_S_INX $rs2))>;
def : Pat<(fcopysign FPR32INX:$rs1, FPR64IN32X:$rs2),
          (FSGNJ_S_INX $rs1, (FCVT_S_D_IN32X $rs2, FRM_DYN))>;

// fmadd: rs1 * rs2 + rs3
def : Pat<(any_fma FPR64IN32X:$rs1, FPR64IN32X:$rs2, FPR64IN32X:$rs3),
          (FMADD_D_IN32X $rs1, $rs2, $rs3, FRM_DYN)>;

// fmsub: rs1 * rs2 - rs3
def : Pat<(any_fma FPR64IN32X:$rs1, FPR64IN32X:$rs2, (fneg FPR64IN32X:$rs3)),
          (FMSUB_D_IN32X FPR64IN32X:$rs1, FPR64IN32X:$rs2, FPR64IN32X:$rs3, FRM_DYN)>;

// fnmsub: -rs1 * rs2 + rs3
def : Pat<(any_fma (fneg FPR64IN32X:$rs1), FPR64IN32X:$rs2, FPR64IN32X:$rs3),
          (FNMSUB_D_IN32X FPR64IN32X:$rs1, FPR64IN32X:$rs2, FPR64IN32X:$rs3, FRM_DYN)>;

// fnmadd: -rs1 * rs2 - rs3
def : Pat<(any_fma (fneg FPR64IN32X:$rs1), FPR64IN32X:$rs2, (fneg FPR64IN32X:$rs3)),
          (FNMADD_D_IN32X FPR64IN32X:$rs1, FPR64IN32X:$rs2, FPR64IN32X:$rs3, FRM_DYN)>;

// fnmadd: -(rs1 * rs2 + rs3) (the nsz flag on the FMA)
def : Pat<(fneg (any_fma_nsz FPR64IN32X:$rs1, FPR64IN32X:$rs2, FPR64IN32X:$rs3)),
          (FNMADD_D_IN32X FPR64IN32X:$rs1, FPR64IN32X:$rs2, FPR64IN32X:$rs3, FRM_DYN)>;
} // Predicates = [HasStdExtZdinx, IsRV32]

// The ratified 20191213 ISA spec defines fmin and fmax in a way that matches
// LLVM's fminnum and fmaxnum.
// <https://github.com/riscv/riscv-isa-manual/commit/cd20cee7efd9bac7c5aa127ec3b451749d2b3cce>.
defm : PatFprFpr_m<fminnum, FMIN_D, DINX>;
defm : PatFprFpr_m<fmaxnum, FMAX_D, DINX>;

/// Setcc
// FIXME: SETEQ/SETLT/SETLE imply nonans, can we pick better instructions for
// strict versions of those.

// Match non-signaling FEQ_D
defm : PatSetCC_m<any_fsetcc,    SETEQ,  FEQ_D,            DINX>;
defm : PatSetCC_m<any_fsetcc,    SETOEQ, FEQ_D,            DINX>;
defm : PatSetCC_m<strict_fsetcc, SETLT,  PseudoQuietFLT_D, DINX>;
defm : PatSetCC_m<strict_fsetcc, SETOLT, PseudoQuietFLT_D, DINX>;
defm : PatSetCC_m<strict_fsetcc, SETLE,  PseudoQuietFLE_D, DINX>;
defm : PatSetCC_m<strict_fsetcc, SETOLE, PseudoQuietFLE_D, DINX>;

let Predicates = [HasStdExtD] in {
// Match signaling FEQ_D
def : Pat<(strict_fsetccs FPR64:$rs1, FPR64:$rs2, SETEQ),
          (AND (FLE_D $rs1, $rs2),
               (FLE_D $rs2, $rs1))>;
def : Pat<(strict_fsetccs FPR64:$rs1, FPR64:$rs2, SETOEQ),
          (AND (FLE_D $rs1, $rs2),
               (FLE_D $rs2, $rs1))>;
// If both operands are the same, use a single FLE.
def : Pat<(strict_fsetccs FPR64:$rs1, FPR64:$rs1, SETEQ),
          (FLE_D $rs1, $rs1)>;
def : Pat<(strict_fsetccs FPR64:$rs1, FPR64:$rs1, SETOEQ),
          (FLE_D $rs1, $rs1)>;

def : PatSetCC<FPR64, any_fsetccs, SETLT, FLT_D>;
def : PatSetCC<FPR64, any_fsetccs, SETOLT, FLT_D>;
def : PatSetCC<FPR64, any_fsetccs, SETLE, FLE_D>;
def : PatSetCC<FPR64, any_fsetccs, SETOLE, FLE_D>;
} // Predicates = [HasStdExtD]

let Predicates = [HasStdExtZdinx, IsRV64] in {
// Match signaling FEQ_D
def : Pat<(strict_fsetccs FPR64INX:$rs1, FPR64INX:$rs2, SETEQ),
          (AND (FLE_D_INX $rs1, $rs2),
               (FLE_D_INX $rs2, $rs1))>;
def : Pat<(strict_fsetccs FPR64INX:$rs1, FPR64INX:$rs2, SETOEQ),
          (AND (FLE_D_INX $rs1, $rs2),
               (FLE_D_INX $rs2, $rs1))>;
// If both operands are the same, use a single FLE.
def : Pat<(strict_fsetccs FPR64INX:$rs1, FPR64INX:$rs1, SETEQ),
          (FLE_D_INX $rs1, $rs1)>;
def : Pat<(strict_fsetccs FPR64INX:$rs1, FPR64INX:$rs1, SETOEQ),
          (FLE_D_INX $rs1, $rs1)>;

def : PatSetCC<FPR64INX, any_fsetccs, SETLT,  FLT_D_INX>;
def : PatSetCC<FPR64INX, any_fsetccs, SETOLT, FLT_D_INX>;
def : PatSetCC<FPR64INX, any_fsetccs, SETLE,  FLE_D_INX>;
def : PatSetCC<FPR64INX, any_fsetccs, SETOLE, FLE_D_INX>;
} // Predicates = [HasStdExtZdinx, IsRV64]

let Predicates = [HasStdExtZdinx, IsRV32] in {
// Match signaling FEQ_D
def : Pat<(strict_fsetccs FPR64IN32X:$rs1, FPR64IN32X:$rs2, SETEQ),
          (AND (FLE_D_IN32X $rs1, $rs2),
               (FLE_D_IN32X $rs2, $rs1))>;
def : Pat<(strict_fsetccs FPR64IN32X:$rs1, FPR64IN32X:$rs2, SETOEQ),
          (AND (FLE_D_IN32X $rs1, $rs2),
               (FLE_D_IN32X $rs2, $rs1))>;
// If both operands are the same, use a single FLE.
def : Pat<(strict_fsetccs FPR64IN32X:$rs1, FPR64IN32X:$rs1, SETEQ),
          (FLE_D_IN32X $rs1, $rs1)>;
def : Pat<(strict_fsetccs FPR64IN32X:$rs1, FPR64IN32X:$rs1, SETOEQ),
          (FLE_D_IN32X $rs1, $rs1)>;

def : PatSetCC<FPR64IN32X, any_fsetccs, SETLT,  FLT_D_IN32X>;
def : PatSetCC<FPR64IN32X, any_fsetccs, SETOLT, FLT_D_IN32X>;
def : PatSetCC<FPR64IN32X, any_fsetccs, SETLE,  FLE_D_IN32X>;
def : PatSetCC<FPR64IN32X, any_fsetccs, SETOLE, FLE_D_IN32X>;
} // Predicates = [HasStdExtZdinx, IsRV32]

let Predicates = [HasStdExtD] in {
defm Select_FPR64 : SelectCC_GPR_rrirr<FPR64>;

def PseudoFROUND_D : PseudoFROUND<FPR64>;

/// Loads

defm : LdPat<load, FLD, f64>;

/// Stores

defm : StPat<store, FSD, FPR64, f64>;

/// Pseudo-instructions needed for the soft-float ABI with RV32D

// Moves two GPRs to an FPR.
let usesCustomInserter = 1 in
def BuildPairF64Pseudo
    : Pseudo<(outs FPR64:$dst), (ins GPR:$src1, GPR:$src2),
             [(set FPR64:$dst, (RISCVBuildPairF64 GPR:$src1, GPR:$src2))]>;

// Moves an FPR to two GPRs.
let usesCustomInserter = 1 in
def SplitF64Pseudo
    : Pseudo<(outs GPR:$dst1, GPR:$dst2), (ins FPR64:$src),
             [(set GPR:$dst1, GPR:$dst2, (RISCVSplitF64 FPR64:$src))]>;

} // Predicates = [HasStdExtD]

let Predicates = [HasStdExtZdinx, IsRV64] in {
defm Select_FPR64INX : SelectCC_GPR_rrirr<FPR64INX>;

def PseudoFROUND_D_INX : PseudoFROUND<FPR64INX>;

/// Loads
def : Pat<(f64 (load (AddrRegImm GPR:$rs1, simm12:$imm12))),
          (COPY_TO_REGCLASS (LD GPR:$rs1, simm12:$imm12), GPRF64)>;

/// Stores
def : Pat<(store (f64 FPR64INX:$rs2), (AddrRegImm GPR:$rs1, simm12:$imm12)),
          (SD (COPY_TO_REGCLASS FPR64INX:$rs2, GPR), GPR:$rs1, simm12:$imm12)>;
} // Predicates = [HasStdExtZdinx, IsRV64]

let Predicates = [HasStdExtZdinx, IsRV32] in {
defm Select_FPR64IN32X : SelectCC_GPR_rrirr<FPR64IN32X>;

def PseudoFROUND_D_IN32X : PseudoFROUND<FPR64IN32X>;

/// Loads
let isCall = 0, mayLoad = 1, mayStore = 0, Size = 8, isCodeGenOnly = 1 in
def PseudoRV32ZdinxLD : Pseudo<(outs GPRPF64:$dst), (ins GPR:$rs1, simm12:$imm12), []>;
def : Pat<(f64 (load (AddrRegImmINX GPR:$rs1, simm12:$imm12))),
          (PseudoRV32ZdinxLD GPR:$rs1, simm12:$imm12)>;

/// Stores
let isCall = 0, mayLoad = 0, mayStore = 1, Size = 8, isCodeGenOnly = 1 in
def PseudoRV32ZdinxSD : Pseudo<(outs), (ins GPRPF64:$rs2, GPRNoX0:$rs1, simm12:$imm12), []>;
def : Pat<(store (f64 GPRPF64:$rs2), (AddrRegImmINX GPR:$rs1, simm12:$imm12)),
          (PseudoRV32ZdinxSD GPRPF64:$rs2, GPR:$rs1, simm12:$imm12)>;

/// Pseudo-instructions needed for the soft-float ABI with RV32D

// Moves two GPRs to an FPR.
let usesCustomInserter = 1 in
def BuildPairF64Pseudo_INX
    : Pseudo<(outs FPR64IN32X:$dst), (ins GPR:$src1, GPR:$src2),
             [(set FPR64IN32X:$dst, (RISCVBuildPairF64 GPR:$src1, GPR:$src2))]>;

// Moves an FPR to two GPRs.
let usesCustomInserter = 1 in
def SplitF64Pseudo_INX
    : Pseudo<(outs GPR:$dst1, GPR:$dst2), (ins FPR64IN32X:$src),
             [(set GPR:$dst1, GPR:$dst2, (RISCVSplitF64 FPR64IN32X:$src))]>;
} // Predicates = [HasStdExtZdinx, IsRV32]

let Predicates = [HasStdExtD, IsRV32] in {

// double->[u]int. Round-to-zero must be used.
def : Pat<(i32 (any_fp_to_sint FPR64:$rs1)), (FCVT_W_D FPR64:$rs1, FRM_RTZ)>;
def : Pat<(i32 (any_fp_to_uint FPR64:$rs1)), (FCVT_WU_D FPR64:$rs1, FRM_RTZ)>;

// Saturating double->[u]int32.
def : Pat<(i32 (riscv_fcvt_x FPR64:$rs1, timm:$frm)), (FCVT_W_D $rs1, timm:$frm)>;
def : Pat<(i32 (riscv_fcvt_xu FPR64:$rs1, timm:$frm)), (FCVT_WU_D $rs1, timm:$frm)>;

// float->int32 with current rounding mode.
def : Pat<(i32 (any_lrint FPR64:$rs1)), (FCVT_W_D $rs1, FRM_DYN)>;

// float->int32 rounded to nearest with ties rounded away from zero.
def : Pat<(i32 (any_lround FPR64:$rs1)), (FCVT_W_D $rs1, FRM_RMM)>;

// [u]int->double.
def : Pat<(any_sint_to_fp (i32 GPR:$rs1)), (FCVT_D_W GPR:$rs1)>;
def : Pat<(any_uint_to_fp (i32 GPR:$rs1)), (FCVT_D_WU GPR:$rs1)>;
} // Predicates = [HasStdExtD, IsRV32]

let Predicates = [HasStdExtZdinx, IsRV32] in {

// double->[u]int. Round-to-zero must be used.
def : Pat<(i32 (any_fp_to_sint FPR64IN32X:$rs1)), (FCVT_W_D_IN32X FPR64IN32X:$rs1, FRM_RTZ)>;
def : Pat<(i32 (any_fp_to_uint FPR64IN32X:$rs1)), (FCVT_WU_D_IN32X FPR64IN32X:$rs1, FRM_RTZ)>;

// Saturating double->[u]int32.
def : Pat<(i32 (riscv_fcvt_x FPR64IN32X:$rs1, timm:$frm)), (FCVT_W_D_IN32X $rs1, timm:$frm)>;
def : Pat<(i32 (riscv_fcvt_xu FPR64IN32X:$rs1, timm:$frm)), (FCVT_WU_D_IN32X $rs1, timm:$frm)>;

// float->int32 with current rounding mode.
def : Pat<(i32 (any_lrint FPR64IN32X:$rs1)), (FCVT_W_D_IN32X $rs1, FRM_DYN)>;

// float->int32 rounded to nearest with ties rounded away from zero.
def : Pat<(i32 (any_lround FPR64IN32X:$rs1)), (FCVT_W_D_IN32X $rs1, FRM_RMM)>;

// [u]int->double.
def : Pat<(any_sint_to_fp (i32 GPR:$rs1)), (FCVT_D_W_IN32X GPR:$rs1)>;
def : Pat<(any_uint_to_fp (i32 GPR:$rs1)), (FCVT_D_WU_IN32X GPR:$rs1)>;
} // Predicates = [HasStdExtZdinx, IsRV32]

let Predicates = [HasStdExtD, IsRV64] in {

// Moves (no conversion)
def : Pat<(bitconvert (i64 GPR:$rs1)), (FMV_D_X GPR:$rs1)>;
def : Pat<(i64 (bitconvert FPR64:$rs1)), (FMV_X_D FPR64:$rs1)>;

// Use target specific isd nodes to help us remember the result is sign
// extended. Matching sext_inreg+fptoui/fptosi may cause the conversion to be
// duplicated if it has another user that didn't need the sign_extend.
def : Pat<(riscv_any_fcvt_w_rv64 FPR64:$rs1, timm:$frm),  (FCVT_W_D $rs1, timm:$frm)>;
def : Pat<(riscv_any_fcvt_wu_rv64 FPR64:$rs1, timm:$frm), (FCVT_WU_D $rs1, timm:$frm)>;

// [u]int32->fp
def : Pat<(any_sint_to_fp (i64 (sexti32 (i64 GPR:$rs1)))), (FCVT_D_W $rs1)>;
def : Pat<(any_uint_to_fp (i64 (zexti32 (i64 GPR:$rs1)))), (FCVT_D_WU $rs1)>;

// Saturating double->[u]int64.
def : Pat<(i64 (riscv_fcvt_x FPR64:$rs1, timm:$frm)), (FCVT_L_D $rs1, timm:$frm)>;
def : Pat<(i64 (riscv_fcvt_xu FPR64:$rs1, timm:$frm)), (FCVT_LU_D $rs1, timm:$frm)>;

// double->[u]int64. Round-to-zero must be used.
def : Pat<(i64 (any_fp_to_sint FPR64:$rs1)), (FCVT_L_D FPR64:$rs1, FRM_RTZ)>;
def : Pat<(i64 (any_fp_to_uint FPR64:$rs1)), (FCVT_LU_D FPR64:$rs1, FRM_RTZ)>;

// double->int64 with current rounding mode.
def : Pat<(i64 (any_lrint FPR64:$rs1)), (FCVT_L_D $rs1, FRM_DYN)>;
def : Pat<(i64 (any_llrint FPR64:$rs1)), (FCVT_L_D $rs1, FRM_DYN)>;

// double->int64 rounded to nearest with ties rounded away from zero.
def : Pat<(i64 (any_lround FPR64:$rs1)), (FCVT_L_D $rs1, FRM_RMM)>;
def : Pat<(i64 (any_llround FPR64:$rs1)), (FCVT_L_D $rs1, FRM_RMM)>;

// [u]int64->fp. Match GCC and default to using dynamic rounding mode.
def : Pat<(any_sint_to_fp (i64 GPR:$rs1)), (FCVT_D_L GPR:$rs1, FRM_DYN)>;
def : Pat<(any_uint_to_fp (i64 GPR:$rs1)), (FCVT_D_LU GPR:$rs1, FRM_DYN)>;
} // Predicates = [HasStdExtD, IsRV64]

let Predicates = [HasStdExtZdinx, IsRV64] in {

// Moves (no conversion)
def : Pat<(f64 (bitconvert (i64 GPR:$rs1))), (COPY_TO_REGCLASS GPR:$rs1, GPRF64)>;
def : Pat<(i64 (bitconvert FPR64INX:$rs1)), (COPY_TO_REGCLASS FPR64INX:$rs1, GPR)>;

// Use target specific isd nodes to help us remember the result is sign
// extended. Matching sext_inreg+fptoui/fptosi may cause the conversion to be
// duplicated if it has another user that didn't need the sign_extend.
def : Pat<(riscv_any_fcvt_w_rv64 FPR64INX:$rs1, timm:$frm),  (FCVT_W_D_INX $rs1, timm:$frm)>;
def : Pat<(riscv_any_fcvt_wu_rv64 FPR64INX:$rs1, timm:$frm), (FCVT_WU_D_INX $rs1, timm:$frm)>;

// [u]int32->fp
def : Pat<(any_sint_to_fp (i64 (sexti32 (i64 GPR:$rs1)))), (FCVT_D_W_INX $rs1)>;
def : Pat<(any_uint_to_fp (i64 (zexti32 (i64 GPR:$rs1)))), (FCVT_D_WU_INX $rs1)>;

// Saturating double->[u]int64.
def : Pat<(i64 (riscv_fcvt_x FPR64INX:$rs1, timm:$frm)), (FCVT_L_D_INX $rs1, timm:$frm)>;
def : Pat<(i64 (riscv_fcvt_xu FPR64INX:$rs1, timm:$frm)), (FCVT_LU_D_INX $rs1, timm:$frm)>;

// double->[u]int64. Round-to-zero must be used.
def : Pat<(i64 (any_fp_to_sint FPR64INX:$rs1)), (FCVT_L_D_INX FPR64INX:$rs1, FRM_RTZ)>;
def : Pat<(i64 (any_fp_to_uint FPR64INX:$rs1)), (FCVT_LU_D_INX FPR64INX:$rs1, FRM_RTZ)>;

// double->int64 with current rounding mode.
def : Pat<(i64 (any_lrint FPR64INX:$rs1)), (FCVT_L_D_INX $rs1, FRM_DYN)>;
def : Pat<(i64 (any_llrint FPR64INX:$rs1)), (FCVT_L_D_INX $rs1, FRM_DYN)>;

// double->int64 rounded to nearest with ties rounded away from zero.
def : Pat<(i64 (any_lround FPR64INX:$rs1)), (FCVT_L_D_INX $rs1, FRM_RMM)>;
def : Pat<(i64 (any_llround FPR64INX:$rs1)), (FCVT_L_D_INX $rs1, FRM_RMM)>;

// [u]int64->fp. Match GCC and default to using dynamic rounding mode.
def : Pat<(any_sint_to_fp (i64 GPR:$rs1)), (FCVT_D_L_INX GPR:$rs1, FRM_DYN)>;
def : Pat<(any_uint_to_fp (i64 GPR:$rs1)), (FCVT_D_LU_INX GPR:$rs1, FRM_DYN)>;
} // Predicates = [HasStdExtZdinx, IsRV64]
