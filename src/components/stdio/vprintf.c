
#define _ELIBC_SOURCE
#include <stdarg.h>
#include <stdio.h>

/*------------------------------------------------------------------------------
// Name: vprintf
//----------------------------------------------------------------------------*/
int vprintf(const char *_RESTRICT format, va_list ap) {
	return vfprintf(stdout, format, ap);
}
