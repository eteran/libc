
#define __ELIBC_SOURCE
#include <stdarg.h>
#include <stdio.h>

/*------------------------------------------------------------------------------
// Name: snprintf
//----------------------------------------------------------------------------*/
int snprintf(char *str, size_t size, const char *format, ...) {
	int ret;
	va_list ap;
	/* TODO: is str or format allowed to be NULL? */
	va_start(ap, format);
	ret = vsnprintf(str, size, format, ap);
	va_end(ap);
	return ret;
}
