
#define __ELIBC_SOURCE
#include <stdio.h>
#include <stdarg.h>

/*------------------------------------------------------------------------------
// Name: scanf
//----------------------------------------------------------------------------*/
int scanf(const char *__ELIBC_RESTRICT format, ...) {
	int ret;
	va_list ap;
	/* TODO: can format be NULL? */
	va_start(ap, format);
	ret = vscanf(format, ap);
	va_end(ap);
	return ret;
}
