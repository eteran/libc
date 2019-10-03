
#ifndef PUTWC_20140316_H_
#define PUTWC_20140316_H_

#include "fputwc.h"

_LIBC_BEGIN

#ifndef putwc
#define putwc(wc, stream) fputwc((wc), (stream))
#endif

_LIBC_END

#endif
