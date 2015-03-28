
#define __ELIBC_SOURCE
#include <stdio.h>
#include <stddef.h>
#include <stdarg.h>

/*------------------------------------------------------------------------------
// Name: fprintf
//----------------------------------------------------------------------------*/
int fprintf(FILE *__ELIBC_RESTRICT stream, const char *__ELIBC_RESTRICT format, ...) {
	int ret;
	va_list ap;
	/* TODO: is stream or format allowed to be NULL? */
	va_start(ap, format);
	ret = vfprintf(stream, format, ap);
	va_end(ap);
	return ret;
}
