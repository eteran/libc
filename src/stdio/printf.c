
#define __ELIBC_SOURCE
#include <stdarg.h>
#include <stdio.h>

/*------------------------------------------------------------------------------
// Name: printf
//----------------------------------------------------------------------------*/
int printf(const char *_RESTRICT format, ...) {
	int ret;
	va_list ap;
	va_start(ap, format);
	ret = vprintf(format, ap);
	va_end(ap);
	return ret;
}
