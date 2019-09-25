
#ifndef REWIND_20051228_H_
#define REWIND_20051228_H_

#include "_file.h"

#ifdef __cplusplus
extern "C" {
#endif

void __elibc_rewind(FILE *stream) _NOEXCEPT;
void rewind(FILE *stream) _NOEXCEPT;

#ifdef __cplusplus
}
#endif

#endif
