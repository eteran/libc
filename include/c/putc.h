
#ifndef PUTC_20051228_H_
#define PUTC_20051228_H_

#include "fputc.h"

_LIBC_BEGIN

#ifndef putc
#define putc(c, stream) fputc((c), (stream))
#endif

_LIBC_END

#endif
