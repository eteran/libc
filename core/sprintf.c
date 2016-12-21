
#define __ELIBC_SOURCE
#include <stdarg.h>
#include <stdio.h>

/*------------------------------------------------------------------------------
// Name: sprintf
//----------------------------------------------------------------------------*/
int sprintf(char *__ELIBC_RESTRICT str, const char *__ELIBC_RESTRICT format, ...) {
	int ret;
	va_list ap;
	va_start(ap, format);
	ret = vsprintf(str, format, ap);
	va_end(ap);
	return ret;
}
