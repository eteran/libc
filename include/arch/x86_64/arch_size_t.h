
#ifndef _ARCH_X86_64_ARCH_SIZE_T_H_20051228_
#define _ARCH_X86_64_ARCH_SIZE_T_H_20051228_

#ifdef __SIZE_TYPE__
	typedef __SIZE_TYPE__ size_t;
#else
	typedef unsigned long int size_t;
#endif

#ifndef __ssize_t_defined
#define __ssize_t_defined
	typedef long int ssize_t;
#endif

#endif
