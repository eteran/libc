
#ifndef GETC_20051228_H_
#define GETC_20051228_H_

#include "fgetc.h"

_LIBC_BEGIN

#ifndef getc
#define getc(stream) fgetc(stream)
#endif

_LIBC_END

#endif
