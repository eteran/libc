
#ifndef ARCH_WCHAR_T_20051228_H_
#define ARCH_WCHAR_T_20051228_H_

/* keyword in C++ */
#ifndef __cplusplus

#ifdef __WCHAR_TYPE__
	typedef __WCHAR_TYPE__ wchar_t;
#else
	typedef unsigned long int wchar_t;
#endif

#endif

#endif
