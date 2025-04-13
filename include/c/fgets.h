
#ifndef _C_FGETS_H_20051228_
#define _C_FGETS_H_20051228_

#include "_file.h"

_LIBC_BEGIN

char *fgets(char *s, int size, FILE *stream) _NOEXCEPT _NON_NULL(1, 3);

_LIBC_END

#endif
