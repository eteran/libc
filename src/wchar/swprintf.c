
#define _ELIBC_SOURCE
#include <stdarg.h>
#include <stdio.h>
#include <wchar.h>

/*------------------------------------------------------------------------------
// Name: swprintf
//----------------------------------------------------------------------------*/
int swprintf(wchar_t *_RESTRICT str, size_t n, const wchar_t *_RESTRICT format, ...) {
	int ret;
	va_list ap;
	va_start(ap, format);
	ret = vswprintf(str, n, format, ap);
	va_end(ap);
	return ret;
}
