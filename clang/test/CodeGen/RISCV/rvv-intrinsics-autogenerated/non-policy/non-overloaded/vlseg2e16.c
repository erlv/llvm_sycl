// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 2
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v -target-feature +zfh \
// RUN:   -target-feature +experimental-zvfh -disable-O0-optnone  \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: define dso_local void @test_vlseg2e16_v_f16mf4
// CHECK-RV64-SAME: (ptr noundef [[V0:%.*]], ptr noundef [[V1:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 1 x half>, <vscale x 1 x half> } @llvm.riscv.vlseg2.nxv1f16.i64(<vscale x 1 x half> poison, <vscale x 1 x half> poison, ptr [[BASE]], i64 [[VL]])
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x half>, <vscale x 1 x half> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 1 x half> [[TMP1]], ptr [[V0]], align 2
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x half>, <vscale x 1 x half> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 1 x half> [[TMP2]], ptr [[V1]], align 2
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e16_v_f16mf4(vfloat16mf4_t *v0, vfloat16mf4_t *v1, const _Float16 *base, size_t vl) {
  return __riscv_vlseg2e16_v_f16mf4(v0, v1, base, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vlseg2e16_v_f16mf2
// CHECK-RV64-SAME: (ptr noundef [[V0:%.*]], ptr noundef [[V1:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 2 x half>, <vscale x 2 x half> } @llvm.riscv.vlseg2.nxv2f16.i64(<vscale x 2 x half> poison, <vscale x 2 x half> poison, ptr [[BASE]], i64 [[VL]])
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 2 x half>, <vscale x 2 x half> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 2 x half> [[TMP1]], ptr [[V0]], align 2
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 2 x half>, <vscale x 2 x half> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 2 x half> [[TMP2]], ptr [[V1]], align 2
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e16_v_f16mf2(vfloat16mf2_t *v0, vfloat16mf2_t *v1, const _Float16 *base, size_t vl) {
  return __riscv_vlseg2e16_v_f16mf2(v0, v1, base, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vlseg2e16_v_f16m1
// CHECK-RV64-SAME: (ptr noundef [[V0:%.*]], ptr noundef [[V1:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 4 x half>, <vscale x 4 x half> } @llvm.riscv.vlseg2.nxv4f16.i64(<vscale x 4 x half> poison, <vscale x 4 x half> poison, ptr [[BASE]], i64 [[VL]])
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 4 x half>, <vscale x 4 x half> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 4 x half> [[TMP1]], ptr [[V0]], align 2
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 4 x half>, <vscale x 4 x half> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 4 x half> [[TMP2]], ptr [[V1]], align 2
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e16_v_f16m1(vfloat16m1_t *v0, vfloat16m1_t *v1, const _Float16 *base, size_t vl) {
  return __riscv_vlseg2e16_v_f16m1(v0, v1, base, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vlseg2e16_v_f16m2
// CHECK-RV64-SAME: (ptr noundef [[V0:%.*]], ptr noundef [[V1:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 8 x half>, <vscale x 8 x half> } @llvm.riscv.vlseg2.nxv8f16.i64(<vscale x 8 x half> poison, <vscale x 8 x half> poison, ptr [[BASE]], i64 [[VL]])
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 8 x half>, <vscale x 8 x half> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 8 x half> [[TMP1]], ptr [[V0]], align 2
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 8 x half>, <vscale x 8 x half> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 8 x half> [[TMP2]], ptr [[V1]], align 2
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e16_v_f16m2(vfloat16m2_t *v0, vfloat16m2_t *v1, const _Float16 *base, size_t vl) {
  return __riscv_vlseg2e16_v_f16m2(v0, v1, base, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vlseg2e16_v_f16m4
// CHECK-RV64-SAME: (ptr noundef [[V0:%.*]], ptr noundef [[V1:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 16 x half>, <vscale x 16 x half> } @llvm.riscv.vlseg2.nxv16f16.i64(<vscale x 16 x half> poison, <vscale x 16 x half> poison, ptr [[BASE]], i64 [[VL]])
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 16 x half>, <vscale x 16 x half> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 16 x half> [[TMP1]], ptr [[V0]], align 2
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 16 x half>, <vscale x 16 x half> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 16 x half> [[TMP2]], ptr [[V1]], align 2
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e16_v_f16m4(vfloat16m4_t *v0, vfloat16m4_t *v1, const _Float16 *base, size_t vl) {
  return __riscv_vlseg2e16_v_f16m4(v0, v1, base, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vlseg2e16_v_i16mf4
// CHECK-RV64-SAME: (ptr noundef [[V0:%.*]], ptr noundef [[V1:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 1 x i16>, <vscale x 1 x i16> } @llvm.riscv.vlseg2.nxv1i16.i64(<vscale x 1 x i16> poison, <vscale x 1 x i16> poison, ptr [[BASE]], i64 [[VL]])
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x i16>, <vscale x 1 x i16> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 1 x i16> [[TMP1]], ptr [[V0]], align 2
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x i16>, <vscale x 1 x i16> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 1 x i16> [[TMP2]], ptr [[V1]], align 2
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e16_v_i16mf4(vint16mf4_t *v0, vint16mf4_t *v1, const int16_t *base, size_t vl) {
  return __riscv_vlseg2e16_v_i16mf4(v0, v1, base, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vlseg2e16_v_i16mf2
// CHECK-RV64-SAME: (ptr noundef [[V0:%.*]], ptr noundef [[V1:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 2 x i16>, <vscale x 2 x i16> } @llvm.riscv.vlseg2.nxv2i16.i64(<vscale x 2 x i16> poison, <vscale x 2 x i16> poison, ptr [[BASE]], i64 [[VL]])
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 2 x i16>, <vscale x 2 x i16> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 2 x i16> [[TMP1]], ptr [[V0]], align 2
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 2 x i16>, <vscale x 2 x i16> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 2 x i16> [[TMP2]], ptr [[V1]], align 2
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e16_v_i16mf2(vint16mf2_t *v0, vint16mf2_t *v1, const int16_t *base, size_t vl) {
  return __riscv_vlseg2e16_v_i16mf2(v0, v1, base, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vlseg2e16_v_i16m1
// CHECK-RV64-SAME: (ptr noundef [[V0:%.*]], ptr noundef [[V1:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 4 x i16>, <vscale x 4 x i16> } @llvm.riscv.vlseg2.nxv4i16.i64(<vscale x 4 x i16> poison, <vscale x 4 x i16> poison, ptr [[BASE]], i64 [[VL]])
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 4 x i16>, <vscale x 4 x i16> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 4 x i16> [[TMP1]], ptr [[V0]], align 2
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 4 x i16>, <vscale x 4 x i16> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 4 x i16> [[TMP2]], ptr [[V1]], align 2
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e16_v_i16m1(vint16m1_t *v0, vint16m1_t *v1, const int16_t *base, size_t vl) {
  return __riscv_vlseg2e16_v_i16m1(v0, v1, base, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vlseg2e16_v_i16m2
// CHECK-RV64-SAME: (ptr noundef [[V0:%.*]], ptr noundef [[V1:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 8 x i16>, <vscale x 8 x i16> } @llvm.riscv.vlseg2.nxv8i16.i64(<vscale x 8 x i16> poison, <vscale x 8 x i16> poison, ptr [[BASE]], i64 [[VL]])
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 8 x i16>, <vscale x 8 x i16> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 8 x i16> [[TMP1]], ptr [[V0]], align 2
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 8 x i16>, <vscale x 8 x i16> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 8 x i16> [[TMP2]], ptr [[V1]], align 2
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e16_v_i16m2(vint16m2_t *v0, vint16m2_t *v1, const int16_t *base, size_t vl) {
  return __riscv_vlseg2e16_v_i16m2(v0, v1, base, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vlseg2e16_v_i16m4
// CHECK-RV64-SAME: (ptr noundef [[V0:%.*]], ptr noundef [[V1:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 16 x i16>, <vscale x 16 x i16> } @llvm.riscv.vlseg2.nxv16i16.i64(<vscale x 16 x i16> poison, <vscale x 16 x i16> poison, ptr [[BASE]], i64 [[VL]])
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 16 x i16>, <vscale x 16 x i16> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 16 x i16> [[TMP1]], ptr [[V0]], align 2
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 16 x i16>, <vscale x 16 x i16> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 16 x i16> [[TMP2]], ptr [[V1]], align 2
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e16_v_i16m4(vint16m4_t *v0, vint16m4_t *v1, const int16_t *base, size_t vl) {
  return __riscv_vlseg2e16_v_i16m4(v0, v1, base, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vlseg2e16_v_u16mf4
// CHECK-RV64-SAME: (ptr noundef [[V0:%.*]], ptr noundef [[V1:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 1 x i16>, <vscale x 1 x i16> } @llvm.riscv.vlseg2.nxv1i16.i64(<vscale x 1 x i16> poison, <vscale x 1 x i16> poison, ptr [[BASE]], i64 [[VL]])
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x i16>, <vscale x 1 x i16> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 1 x i16> [[TMP1]], ptr [[V0]], align 2
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x i16>, <vscale x 1 x i16> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 1 x i16> [[TMP2]], ptr [[V1]], align 2
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e16_v_u16mf4(vuint16mf4_t *v0, vuint16mf4_t *v1, const uint16_t *base, size_t vl) {
  return __riscv_vlseg2e16_v_u16mf4(v0, v1, base, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vlseg2e16_v_u16mf2
// CHECK-RV64-SAME: (ptr noundef [[V0:%.*]], ptr noundef [[V1:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 2 x i16>, <vscale x 2 x i16> } @llvm.riscv.vlseg2.nxv2i16.i64(<vscale x 2 x i16> poison, <vscale x 2 x i16> poison, ptr [[BASE]], i64 [[VL]])
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 2 x i16>, <vscale x 2 x i16> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 2 x i16> [[TMP1]], ptr [[V0]], align 2
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 2 x i16>, <vscale x 2 x i16> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 2 x i16> [[TMP2]], ptr [[V1]], align 2
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e16_v_u16mf2(vuint16mf2_t *v0, vuint16mf2_t *v1, const uint16_t *base, size_t vl) {
  return __riscv_vlseg2e16_v_u16mf2(v0, v1, base, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vlseg2e16_v_u16m1
// CHECK-RV64-SAME: (ptr noundef [[V0:%.*]], ptr noundef [[V1:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 4 x i16>, <vscale x 4 x i16> } @llvm.riscv.vlseg2.nxv4i16.i64(<vscale x 4 x i16> poison, <vscale x 4 x i16> poison, ptr [[BASE]], i64 [[VL]])
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 4 x i16>, <vscale x 4 x i16> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 4 x i16> [[TMP1]], ptr [[V0]], align 2
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 4 x i16>, <vscale x 4 x i16> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 4 x i16> [[TMP2]], ptr [[V1]], align 2
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e16_v_u16m1(vuint16m1_t *v0, vuint16m1_t *v1, const uint16_t *base, size_t vl) {
  return __riscv_vlseg2e16_v_u16m1(v0, v1, base, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vlseg2e16_v_u16m2
// CHECK-RV64-SAME: (ptr noundef [[V0:%.*]], ptr noundef [[V1:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 8 x i16>, <vscale x 8 x i16> } @llvm.riscv.vlseg2.nxv8i16.i64(<vscale x 8 x i16> poison, <vscale x 8 x i16> poison, ptr [[BASE]], i64 [[VL]])
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 8 x i16>, <vscale x 8 x i16> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 8 x i16> [[TMP1]], ptr [[V0]], align 2
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 8 x i16>, <vscale x 8 x i16> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 8 x i16> [[TMP2]], ptr [[V1]], align 2
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e16_v_u16m2(vuint16m2_t *v0, vuint16m2_t *v1, const uint16_t *base, size_t vl) {
  return __riscv_vlseg2e16_v_u16m2(v0, v1, base, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vlseg2e16_v_u16m4
// CHECK-RV64-SAME: (ptr noundef [[V0:%.*]], ptr noundef [[V1:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 16 x i16>, <vscale x 16 x i16> } @llvm.riscv.vlseg2.nxv16i16.i64(<vscale x 16 x i16> poison, <vscale x 16 x i16> poison, ptr [[BASE]], i64 [[VL]])
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 16 x i16>, <vscale x 16 x i16> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 16 x i16> [[TMP1]], ptr [[V0]], align 2
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 16 x i16>, <vscale x 16 x i16> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 16 x i16> [[TMP2]], ptr [[V1]], align 2
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e16_v_u16m4(vuint16m4_t *v0, vuint16m4_t *v1, const uint16_t *base, size_t vl) {
  return __riscv_vlseg2e16_v_u16m4(v0, v1, base, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vlseg2e16_v_f16mf4_m
// CHECK-RV64-SAME: (ptr noundef [[V0:%.*]], ptr noundef [[V1:%.*]], <vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 1 x half>, <vscale x 1 x half> } @llvm.riscv.vlseg2.mask.nxv1f16.i64(<vscale x 1 x half> poison, <vscale x 1 x half> poison, ptr [[BASE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x half>, <vscale x 1 x half> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 1 x half> [[TMP1]], ptr [[V0]], align 2
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x half>, <vscale x 1 x half> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 1 x half> [[TMP2]], ptr [[V1]], align 2
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e16_v_f16mf4_m(vfloat16mf4_t *v0, vfloat16mf4_t *v1, vbool64_t mask, const _Float16 *base, size_t vl) {
  return __riscv_vlseg2e16_v_f16mf4_m(v0, v1, mask, base, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vlseg2e16_v_f16mf2_m
// CHECK-RV64-SAME: (ptr noundef [[V0:%.*]], ptr noundef [[V1:%.*]], <vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 2 x half>, <vscale x 2 x half> } @llvm.riscv.vlseg2.mask.nxv2f16.i64(<vscale x 2 x half> poison, <vscale x 2 x half> poison, ptr [[BASE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 2 x half>, <vscale x 2 x half> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 2 x half> [[TMP1]], ptr [[V0]], align 2
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 2 x half>, <vscale x 2 x half> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 2 x half> [[TMP2]], ptr [[V1]], align 2
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e16_v_f16mf2_m(vfloat16mf2_t *v0, vfloat16mf2_t *v1, vbool32_t mask, const _Float16 *base, size_t vl) {
  return __riscv_vlseg2e16_v_f16mf2_m(v0, v1, mask, base, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vlseg2e16_v_f16m1_m
// CHECK-RV64-SAME: (ptr noundef [[V0:%.*]], ptr noundef [[V1:%.*]], <vscale x 4 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 4 x half>, <vscale x 4 x half> } @llvm.riscv.vlseg2.mask.nxv4f16.i64(<vscale x 4 x half> poison, <vscale x 4 x half> poison, ptr [[BASE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 4 x half>, <vscale x 4 x half> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 4 x half> [[TMP1]], ptr [[V0]], align 2
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 4 x half>, <vscale x 4 x half> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 4 x half> [[TMP2]], ptr [[V1]], align 2
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e16_v_f16m1_m(vfloat16m1_t *v0, vfloat16m1_t *v1, vbool16_t mask, const _Float16 *base, size_t vl) {
  return __riscv_vlseg2e16_v_f16m1_m(v0, v1, mask, base, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vlseg2e16_v_f16m2_m
// CHECK-RV64-SAME: (ptr noundef [[V0:%.*]], ptr noundef [[V1:%.*]], <vscale x 8 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 8 x half>, <vscale x 8 x half> } @llvm.riscv.vlseg2.mask.nxv8f16.i64(<vscale x 8 x half> poison, <vscale x 8 x half> poison, ptr [[BASE]], <vscale x 8 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 8 x half>, <vscale x 8 x half> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 8 x half> [[TMP1]], ptr [[V0]], align 2
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 8 x half>, <vscale x 8 x half> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 8 x half> [[TMP2]], ptr [[V1]], align 2
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e16_v_f16m2_m(vfloat16m2_t *v0, vfloat16m2_t *v1, vbool8_t mask, const _Float16 *base, size_t vl) {
  return __riscv_vlseg2e16_v_f16m2_m(v0, v1, mask, base, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vlseg2e16_v_f16m4_m
// CHECK-RV64-SAME: (ptr noundef [[V0:%.*]], ptr noundef [[V1:%.*]], <vscale x 16 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 16 x half>, <vscale x 16 x half> } @llvm.riscv.vlseg2.mask.nxv16f16.i64(<vscale x 16 x half> poison, <vscale x 16 x half> poison, ptr [[BASE]], <vscale x 16 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 16 x half>, <vscale x 16 x half> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 16 x half> [[TMP1]], ptr [[V0]], align 2
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 16 x half>, <vscale x 16 x half> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 16 x half> [[TMP2]], ptr [[V1]], align 2
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e16_v_f16m4_m(vfloat16m4_t *v0, vfloat16m4_t *v1, vbool4_t mask, const _Float16 *base, size_t vl) {
  return __riscv_vlseg2e16_v_f16m4_m(v0, v1, mask, base, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vlseg2e16_v_i16mf4_m
// CHECK-RV64-SAME: (ptr noundef [[V0:%.*]], ptr noundef [[V1:%.*]], <vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 1 x i16>, <vscale x 1 x i16> } @llvm.riscv.vlseg2.mask.nxv1i16.i64(<vscale x 1 x i16> poison, <vscale x 1 x i16> poison, ptr [[BASE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x i16>, <vscale x 1 x i16> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 1 x i16> [[TMP1]], ptr [[V0]], align 2
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x i16>, <vscale x 1 x i16> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 1 x i16> [[TMP2]], ptr [[V1]], align 2
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e16_v_i16mf4_m(vint16mf4_t *v0, vint16mf4_t *v1, vbool64_t mask, const int16_t *base, size_t vl) {
  return __riscv_vlseg2e16_v_i16mf4_m(v0, v1, mask, base, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vlseg2e16_v_i16mf2_m
// CHECK-RV64-SAME: (ptr noundef [[V0:%.*]], ptr noundef [[V1:%.*]], <vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 2 x i16>, <vscale x 2 x i16> } @llvm.riscv.vlseg2.mask.nxv2i16.i64(<vscale x 2 x i16> poison, <vscale x 2 x i16> poison, ptr [[BASE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 2 x i16>, <vscale x 2 x i16> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 2 x i16> [[TMP1]], ptr [[V0]], align 2
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 2 x i16>, <vscale x 2 x i16> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 2 x i16> [[TMP2]], ptr [[V1]], align 2
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e16_v_i16mf2_m(vint16mf2_t *v0, vint16mf2_t *v1, vbool32_t mask, const int16_t *base, size_t vl) {
  return __riscv_vlseg2e16_v_i16mf2_m(v0, v1, mask, base, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vlseg2e16_v_i16m1_m
// CHECK-RV64-SAME: (ptr noundef [[V0:%.*]], ptr noundef [[V1:%.*]], <vscale x 4 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 4 x i16>, <vscale x 4 x i16> } @llvm.riscv.vlseg2.mask.nxv4i16.i64(<vscale x 4 x i16> poison, <vscale x 4 x i16> poison, ptr [[BASE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 4 x i16>, <vscale x 4 x i16> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 4 x i16> [[TMP1]], ptr [[V0]], align 2
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 4 x i16>, <vscale x 4 x i16> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 4 x i16> [[TMP2]], ptr [[V1]], align 2
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e16_v_i16m1_m(vint16m1_t *v0, vint16m1_t *v1, vbool16_t mask, const int16_t *base, size_t vl) {
  return __riscv_vlseg2e16_v_i16m1_m(v0, v1, mask, base, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vlseg2e16_v_i16m2_m
// CHECK-RV64-SAME: (ptr noundef [[V0:%.*]], ptr noundef [[V1:%.*]], <vscale x 8 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 8 x i16>, <vscale x 8 x i16> } @llvm.riscv.vlseg2.mask.nxv8i16.i64(<vscale x 8 x i16> poison, <vscale x 8 x i16> poison, ptr [[BASE]], <vscale x 8 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 8 x i16>, <vscale x 8 x i16> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 8 x i16> [[TMP1]], ptr [[V0]], align 2
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 8 x i16>, <vscale x 8 x i16> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 8 x i16> [[TMP2]], ptr [[V1]], align 2
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e16_v_i16m2_m(vint16m2_t *v0, vint16m2_t *v1, vbool8_t mask, const int16_t *base, size_t vl) {
  return __riscv_vlseg2e16_v_i16m2_m(v0, v1, mask, base, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vlseg2e16_v_i16m4_m
// CHECK-RV64-SAME: (ptr noundef [[V0:%.*]], ptr noundef [[V1:%.*]], <vscale x 16 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 16 x i16>, <vscale x 16 x i16> } @llvm.riscv.vlseg2.mask.nxv16i16.i64(<vscale x 16 x i16> poison, <vscale x 16 x i16> poison, ptr [[BASE]], <vscale x 16 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 16 x i16>, <vscale x 16 x i16> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 16 x i16> [[TMP1]], ptr [[V0]], align 2
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 16 x i16>, <vscale x 16 x i16> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 16 x i16> [[TMP2]], ptr [[V1]], align 2
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e16_v_i16m4_m(vint16m4_t *v0, vint16m4_t *v1, vbool4_t mask, const int16_t *base, size_t vl) {
  return __riscv_vlseg2e16_v_i16m4_m(v0, v1, mask, base, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vlseg2e16_v_u16mf4_m
// CHECK-RV64-SAME: (ptr noundef [[V0:%.*]], ptr noundef [[V1:%.*]], <vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 1 x i16>, <vscale x 1 x i16> } @llvm.riscv.vlseg2.mask.nxv1i16.i64(<vscale x 1 x i16> poison, <vscale x 1 x i16> poison, ptr [[BASE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x i16>, <vscale x 1 x i16> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 1 x i16> [[TMP1]], ptr [[V0]], align 2
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x i16>, <vscale x 1 x i16> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 1 x i16> [[TMP2]], ptr [[V1]], align 2
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e16_v_u16mf4_m(vuint16mf4_t *v0, vuint16mf4_t *v1, vbool64_t mask, const uint16_t *base, size_t vl) {
  return __riscv_vlseg2e16_v_u16mf4_m(v0, v1, mask, base, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vlseg2e16_v_u16mf2_m
// CHECK-RV64-SAME: (ptr noundef [[V0:%.*]], ptr noundef [[V1:%.*]], <vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 2 x i16>, <vscale x 2 x i16> } @llvm.riscv.vlseg2.mask.nxv2i16.i64(<vscale x 2 x i16> poison, <vscale x 2 x i16> poison, ptr [[BASE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 2 x i16>, <vscale x 2 x i16> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 2 x i16> [[TMP1]], ptr [[V0]], align 2
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 2 x i16>, <vscale x 2 x i16> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 2 x i16> [[TMP2]], ptr [[V1]], align 2
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e16_v_u16mf2_m(vuint16mf2_t *v0, vuint16mf2_t *v1, vbool32_t mask, const uint16_t *base, size_t vl) {
  return __riscv_vlseg2e16_v_u16mf2_m(v0, v1, mask, base, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vlseg2e16_v_u16m1_m
// CHECK-RV64-SAME: (ptr noundef [[V0:%.*]], ptr noundef [[V1:%.*]], <vscale x 4 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 4 x i16>, <vscale x 4 x i16> } @llvm.riscv.vlseg2.mask.nxv4i16.i64(<vscale x 4 x i16> poison, <vscale x 4 x i16> poison, ptr [[BASE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 4 x i16>, <vscale x 4 x i16> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 4 x i16> [[TMP1]], ptr [[V0]], align 2
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 4 x i16>, <vscale x 4 x i16> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 4 x i16> [[TMP2]], ptr [[V1]], align 2
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e16_v_u16m1_m(vuint16m1_t *v0, vuint16m1_t *v1, vbool16_t mask, const uint16_t *base, size_t vl) {
  return __riscv_vlseg2e16_v_u16m1_m(v0, v1, mask, base, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vlseg2e16_v_u16m2_m
// CHECK-RV64-SAME: (ptr noundef [[V0:%.*]], ptr noundef [[V1:%.*]], <vscale x 8 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 8 x i16>, <vscale x 8 x i16> } @llvm.riscv.vlseg2.mask.nxv8i16.i64(<vscale x 8 x i16> poison, <vscale x 8 x i16> poison, ptr [[BASE]], <vscale x 8 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 8 x i16>, <vscale x 8 x i16> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 8 x i16> [[TMP1]], ptr [[V0]], align 2
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 8 x i16>, <vscale x 8 x i16> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 8 x i16> [[TMP2]], ptr [[V1]], align 2
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e16_v_u16m2_m(vuint16m2_t *v0, vuint16m2_t *v1, vbool8_t mask, const uint16_t *base, size_t vl) {
  return __riscv_vlseg2e16_v_u16m2_m(v0, v1, mask, base, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vlseg2e16_v_u16m4_m
// CHECK-RV64-SAME: (ptr noundef [[V0:%.*]], ptr noundef [[V1:%.*]], <vscale x 16 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 16 x i16>, <vscale x 16 x i16> } @llvm.riscv.vlseg2.mask.nxv16i16.i64(<vscale x 16 x i16> poison, <vscale x 16 x i16> poison, ptr [[BASE]], <vscale x 16 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 16 x i16>, <vscale x 16 x i16> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 16 x i16> [[TMP1]], ptr [[V0]], align 2
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 16 x i16>, <vscale x 16 x i16> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 16 x i16> [[TMP2]], ptr [[V1]], align 2
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e16_v_u16m4_m(vuint16m4_t *v0, vuint16m4_t *v1, vbool4_t mask, const uint16_t *base, size_t vl) {
  return __riscv_vlseg2e16_v_u16m4_m(v0, v1, mask, base, vl);
}

