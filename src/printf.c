
#define __ELIBC_SOURCE
#include <stdio.h>
#include <stdarg.h>

/*------------------------------------------------------------------------------
// Name: printf
//----------------------------------------------------------------------------*/
int printf(const char *__ELIBC_RESTRICT format, ...) {
	int ret;
	va_list ap;
	/* TODO: is format allowed to be NULL? */
	va_start(ap, format);
	ret = vprintf(format, ap);
	va_end(ap);
	return ret;
}
