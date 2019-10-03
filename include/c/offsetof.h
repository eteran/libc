
#ifndef OFFSETOF_20110828_H_
#define OFFSETOF_20110828_H_

#include "arch_size_t.h"

#if defined(__GNUC__)
#define offsetof(type, mbr)  __builtin_offsetof(type, mbr)
#else
#define offsetof(type, mbr) ((size_t)&(((type*)0)->mbr))
#endif

#endif
