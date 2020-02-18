
#ifndef _C_GETC_H_20051228_
#define _C_GETC_H_20051228_

#include "fgetc.h"

_LIBC_BEGIN

#ifndef getc
#define getc(stream) fgetc(stream)
#endif

_LIBC_END

#endif
