
#define __ELIBC_SOURCE
#include <stdio.h>
#include <stddef.h>
#include <stdarg.h>

/*------------------------------------------------------------------------------
// Name: fprintf
//----------------------------------------------------------------------------*/
int fprintf(FILE *_RESTRICT stream, const char *_RESTRICT format, ...) {
	int ret;
	va_list ap;
	va_start(ap, format);
	ret = vfprintf(stream, format, ap);
	va_end(ap);
	return ret;
}
