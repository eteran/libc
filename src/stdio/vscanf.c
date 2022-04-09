
#define _ELIBC_SOURCE
#include <stdarg.h>
#include <stdio.h>

/*------------------------------------------------------------------------------
// Name: vscanf
//----------------------------------------------------------------------------*/
int vscanf(const char *_RESTRICT format, va_list ap) {
	return vfscanf(stdin, format, ap);
}
