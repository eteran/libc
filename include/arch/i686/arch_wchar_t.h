
#ifndef _ARCH_I686_ARCH_WCHAR_T_H_20051228_
#define _ARCH_I686_ARCH_WCHAR_T_H_20051228_

/* keyword in C++ */
#ifndef __cplusplus

#ifdef __WCHAR_TYPE__
	typedef __WCHAR_TYPE__ wchar_t;
#else
	typedef unsigned long int wchar_t;
#endif

#endif

#endif
