
#ifndef PUTWC_20140316_H_
#define PUTWC_20140316_H_

#include "fputwc.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef putwc
#define putwc(wc, stream) fputwc((wc), (stream))
#endif

#ifdef __cplusplus
}
#endif

#endif
