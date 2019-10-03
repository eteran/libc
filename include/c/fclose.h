
#ifndef FCLOSE_20051228_H_
#define FCLOSE_20051228_H_

#include "_file.h"

_LIBC_BEGIN

int __elibc_fclose(FILE *stream) _NOEXCEPT;
int fclose(FILE *stream) _NOEXCEPT;

_LIBC_END

#endif
