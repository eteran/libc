
#define _ELIBC_SOURCE
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <wchar.h>

/*------------------------------------------------------------------------------
// Name: fwprintf
//----------------------------------------------------------------------------*/
int fwprintf(FILE *_RESTRICT stream, const wchar_t *_RESTRICT format, ...) {
	int ret;
	va_list ap;
	va_start(ap, format);
	ret = vfwprintf(stream, format, ap);
	va_end(ap);
	return ret;
}
