
#ifndef _C_OFFSETOF_H_20110828_
#define _C_OFFSETOF_H_20110828_

#include "arch_size_t.h"

#if defined(__GNUC__)
#define offsetof(type, mbr) __builtin_offsetof(type, mbr)
#else
#define offsetof(type, mbr) ((size_t) & (((type *)0)->mbr))
#endif

#endif
