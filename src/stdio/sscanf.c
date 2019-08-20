
#define __ELIBC_SOURCE
#include <stdio.h>
#include <stdarg.h>

/*------------------------------------------------------------------------------
// Name:
//----------------------------------------------------------------------------*/
int sscanf(const char *__ELIBC_RESTRICT str, const char *__ELIBC_RESTRICT format, ...) {
	int ret;
	va_list ap;
	va_start(ap, format);
	ret = vsscanf(str, format, ap);
	va_end(ap);
	return ret;
}
