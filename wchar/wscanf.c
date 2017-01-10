
#define __ELIBC_SOURCE
#include <stdio.h>
#include <wchar.h>
#include <stdarg.h>

/*------------------------------------------------------------------------------
// Name: wscanf
//----------------------------------------------------------------------------*/
int wscanf(const wchar_t *__ELIBC_RESTRICT format, ...) {
	int ret;
	va_list ap;
	va_start(ap, format);
	ret = vwscanf(format, ap);
	va_end(ap);
	return ret;
}
