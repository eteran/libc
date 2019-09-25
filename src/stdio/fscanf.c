
#define __ELIBC_SOURCE
#include <stdio.h>
#include <stdarg.h>
#include <assert.h>

/*------------------------------------------------------------------------------
// Name: fscanf
//----------------------------------------------------------------------------*/
int fscanf(FILE *_RESTRICT stream, const char *_RESTRICT format, ...) {
	int ret;
	va_list ap;

	assert(stream);
	assert(format);

	va_start(ap, format);
	ret = vfscanf(stream, format, ap);
	va_end(ap);
	return ret;
}
