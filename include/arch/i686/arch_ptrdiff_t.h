
#ifndef ARCH_PTRDIFF_20051228_H_
#define ARCH_PTRDIFF_20051228_H_

#ifdef __PTRDIFF_TYPE__
	typedef __PTRDIFF_TYPE__ ptrdiff_t;
#else
	typedef int ptrdiff_t;
#endif

#endif
