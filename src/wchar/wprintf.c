
#define __ELIBC_SOURCE
#include <stdio.h>
#include <stdarg.h>
#include <wchar.h>

/*------------------------------------------------------------------------------
// Name: wprintf
//----------------------------------------------------------------------------*/
int wprintf(const wchar_t *_RESTRICT format, ...) {
	int ret;
	va_list ap;
	va_start(ap, format);
	ret = vwprintf(format, ap);
	va_end(ap);
	return ret;
}
