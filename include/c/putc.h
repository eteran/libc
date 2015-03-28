
#ifndef PUTC_20051228_H_
#define PUTC_20051228_H_

#include "fputc.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef putc
#define putc(c, stream) fputc((c), (stream))
#endif

#ifdef __cplusplus
}
#endif

#endif
