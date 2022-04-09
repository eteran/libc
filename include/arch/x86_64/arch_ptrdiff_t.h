
#ifndef _ARCH_X86_64_ARCH_PTRDIFF_T_H_20051228_
#define _ARCH_X86_64_ARCH_PTRDIFF_T_H_20051228_

#ifdef __PTRDIFF_TYPE__
typedef __PTRDIFF_TYPE__ ptrdiff_t;
#else
typedef long int ptrdiff_t;
#endif

#endif
