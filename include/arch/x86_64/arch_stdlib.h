
#ifndef ARCH_STDLIB_20051228_H_
#define ARCH_STDLIB_20051228_H_

#ifdef __INT_MAX__
	#define RAND_MAX __INT_MAX__
#else
	#define RAND_MAX 0x7fffffff
#endif

#endif
