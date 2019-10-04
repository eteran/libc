
#define __ELIBC_SOURCE
#include <stdarg.h>
#include <stdio.h>

/*------------------------------------------------------------------------------
// Name:
//----------------------------------------------------------------------------*/
int sscanf(const char *_RESTRICT str, const char *_RESTRICT format, ...) {
	int ret;
	va_list ap;
	va_start(ap, format);
	ret = vsscanf(str, format, ap);
	va_end(ap);
	return ret;
}
