
#define __ELIBC_SOURCE
#include <stdarg.h>
#include <stdio.h>
#include <wchar.h>

/*------------------------------------------------------------------------------
// Name: wscanf
//----------------------------------------------------------------------------*/
int wscanf(const wchar_t *_RESTRICT format, ...) {
	int ret;
	va_list ap;
	va_start(ap, format);
	ret = vwscanf(format, ap);
	va_end(ap);
	return ret;
}
