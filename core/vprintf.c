
#define __ELIBC_SOURCE
#include <stdarg.h>
#include <stdio.h>

/*------------------------------------------------------------------------------
// Name: vprintf
//----------------------------------------------------------------------------*/
int vprintf(const char *__ELIBC_RESTRICT format, va_list ap) {
	/* TODO: is format allowed to be NULL? */
	return vfprintf(stdout, format, ap);
}
