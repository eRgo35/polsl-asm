#pragma once

#include "resource.h"
#include <windows.h>
#include <xmmintrin.h>

#ifdef _MSC_VER // if Visual C/C++
__inline __m64 _mm_set_pi64x(const __int64 i) {
  union {
    __int64 i;
    __m64 v;
  } u;

  u.i = i;
  return u.v;
}
#endif

// external JALib3.dll library function definition prototype
extern "C" int _stdcall MyProc1(int a1, int b1);
extern "C" int _stdcall MyProc2(int a2, int b2, int c2, int d2, int e2, int f2);
extern "C" int _stdcall MyProc3(float a3, double b3, float c3, double d3, float e3, float f3);
extern "C" int _stdcall MyProc4(int a4, double b4, int c4, float d4, int e4, float f4);
extern "C" int _stdcall MyProc5(__m64 a5, __m128 b5);
extern "C" int _stdcall ModifyBuffer(BYTE *bufp);
