
#ifndef VSCANF_20051228_H_
#define VSCANF_20051228_H_

#include "arch_va_list.h"

#ifdef __cplusplus
extern "C" {
#endif

int vscanf(const char *_RESTRICT format, va_list ap) _NOEXCEPT;

#ifdef __cplusplus
}
#endif

#endif
