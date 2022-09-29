
#ifndef _C_GETWC_H_20140316_
#define _C_GETWC_H_20140316_

#include "_file.h"
#include "_wint_t.h"

_LIBC_BEGIN

#ifndef getwc
#define getwc(stream) fgetwc(stream)
#endif

_LIBC_END

#endif
