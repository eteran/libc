
#ifndef FCLOSE_20051228_H_
#define FCLOSE_20051228_H_

#include "_file.h"

#ifdef __cplusplus
extern "C" {
#endif

int __elibc_fclose(FILE *stream) _NOEXCEPT;
int fclose(FILE *stream) _NOEXCEPT;

#ifdef __cplusplus
}
#endif

#endif
