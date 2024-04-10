#pragma once

#include "resource.h"
#include <windows.h>

uint64_t GetNowTickCount();
LONGLONG PerformanceCounter();
uint64_t elapsed(uint32_t start_hi, uint32_t start_lo, uint32_t end_hi, uint32_t end_lo);

extern "C" int _stdcall FindChar_1(void);
extern "C" int _stdcall FindChar_2(void);
extern "C" int _stdcall FindChar_3(LPBYTE String);
extern "C" int _stdcall FindChar_4(void);
extern "C" int _stdcall FindChar_5(void);
extern "C" int _stdcall FindChar_6(void);
extern "C" int _stdcall FindChar_7(void);
