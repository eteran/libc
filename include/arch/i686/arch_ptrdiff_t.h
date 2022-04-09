
#ifndef _ARCH_I686_ARCH_PTRDIFF_T_H_20051228_
#define _ARCH_I686_ARCH_PTRDIFF_T_H_20051228_

#ifdef __PTRDIFF_TYPE__
typedef __PTRDIFF_TYPE__ ptrdiff_t;
#else
typedef int ptrdiff_t;
#endif

#endif
