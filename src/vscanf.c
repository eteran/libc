
#define __ELIBC_SOURCE
#include <stdarg.h>
#include <stdio.h>

/*------------------------------------------------------------------------------
// Name: vscanf
//----------------------------------------------------------------------------*/
int vscanf(const char *__ELIBC_RESTRICT format, va_list ap) {
	/* TODO: can format be NULL? */
	return vfscanf(stdin, format, ap);
}
