#pragma once
#include <stdint.h>

#define SPCTOOLS_API __declspec(dllexport)

#ifdef __cplusplus
extern "C" {
#endif

void SPCTOOLS_API Plot(double* x, double* y, size_t length);

void SPCTOOLS_API Hold(uint8_t flag);

void SPCTOOLS_API Show();

#ifdef __cplusplus
}
#endif
