
#ifndef _C_PUTWC_H_20140316_
#define _C_PUTWC_H_20140316_

#include "fputwc.h"

_LIBC_BEGIN

#ifndef putwc
#define putwc(wc, stream) fputwc((wc), (stream))
#endif

_LIBC_END

#endif
