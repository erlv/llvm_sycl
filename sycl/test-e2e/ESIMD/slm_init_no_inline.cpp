// RUN: %{build} -fno-inline-functions -o %t.out
// RUN: %{run} %t.out
// RUN: %{build} -O0 -o %t0.out
// RUN: %{run} %t0.out

// TODO: gpu driver cannot yet handle the IR generated without
// inlining and especially without optimizations.
// XFAIL: gpu && !esimd_emulator

#include "esimd_test_utils.hpp"

#include <iostream>
#include <sycl/ext/intel/esimd.hpp>
#include <sycl/sycl.hpp>

using namespace sycl;
using namespace sycl::ext::intel::esimd;

int main() {
  constexpr int VL = 16;

  queue Q(esimd_test::ESIMDSelector, esimd_test::createExceptionHandler());
  auto D = Q.get_device();
  std::cout << "Running on " << D.get_info<info::device::name>()
            << ", driver=" << D.get_info<info::device::driver_version>()
            << std::endl;

  constexpr int Size = VL * 2;
  int *A = malloc_shared<int>(Size, Q);
  for (int I = 0; I < Size; ++I)
    A[I] = 0;

  try {
    nd_range<1> NDR{range<1>{Size / VL}, range<1>{Size / VL}};
    Q.parallel_for(NDR, [=](nd_item<1> NDI) SYCL_ESIMD_KERNEL {
       slm_init<Size>();
       int I = NDI.get_local_id(0);
       simd<int, VL> V(I * VL, 1);
       slm_block_store(I * VL * sizeof(int), V);

       barrier();

       if (I == 0) {
         V = slm_block_load<int, VL>(0);
         V.copy_to(A);
         V = slm_block_load<int, VL>(VL * sizeof(int));
         V.copy_to(A + VL);
       }
     }).wait();
  } catch (sycl::exception const &e) {
    std::cout << "SYCL exception caught: " << e.what() << '\n';
    free(A, Q);
    return 1;
  }

  int NumErrors = 0;
  for (int I = 0; I < Size; ++I) {
    if (A[I] != I) {
      std::cout << "Error: " << A[I] << " != " << I << std::endl;
      NumErrors++;
    }
  }

  free(A, Q);
  std::cout << (NumErrors > 0 ? "FAILED\n" : "Passed\n");
  return NumErrors;
}
