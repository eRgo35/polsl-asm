#ifndef RAD_TO_DEG_HPP
#define RAD_TO_DEG_HPP

#define _USE_MATH_DEFINES
#include <cmath>

#include <emmintrin.h> // SSE2 instructions library header
#include <Windows.h>

double RadToDegCpp(double dRad, BOOL bSSE2);

#endif