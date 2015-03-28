
#ifndef ARCH_SIZE_T_20051228_H_
#define ARCH_SIZE_T_20051228_H_

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
