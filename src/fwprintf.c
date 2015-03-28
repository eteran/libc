
#define __ELIBC_SOURCE
#include <stdio.h>
#include <stddef.h>
#include <stdarg.h>
#include <wchar.h>

/*------------------------------------------------------------------------------
// Name: fwprintf
//----------------------------------------------------------------------------*/
int fwprintf(FILE *__ELIBC_RESTRICT stream, const wchar_t *__ELIBC_RESTRICT format, ...) {
	int ret;
	va_list ap;
	/* TODO: is stream or format allowed to be NULL? */
	va_start(ap, format);
	ret = vfwprintf(stream, format, ap);
	va_end(ap);
	return ret;
}
