#ifndef RAD_TO_DEG_ASM_HPP
#define RAD_TO_DEG_ASM_HPP

extern "C" int _stdcall RadToDegAsm(int dRad, bool isSSE2);

extern "C" bool _stdcall CpuIdAsm();

#endif