
#ifndef GETC_20051228_H_
#define GETC_20051228_H_

#include "fgetc.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef getc
#define getc(stream) fgetc(stream)
#endif

#ifdef __cplusplus
}
#endif

#endif
