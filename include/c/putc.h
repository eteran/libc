
#ifndef _C_PUTC_H_20051228_
#define _C_PUTC_H_20051228_

#include "fputc.h"

_LIBC_BEGIN

#ifndef putc
#define putc(c, stream) fputc((c), (stream))
#endif

_LIBC_END

#endif
