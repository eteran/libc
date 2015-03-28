
#define __ELIBC_SOURCE
#include <stdarg.h>
#include <stdio.h>
#include <wchar.h>

/*------------------------------------------------------------------------------
// Name: vwprintf
//----------------------------------------------------------------------------*/
int vwprintf(const wchar_t *format, va_list ap) {
	/* TODO: is format allowed to be NULL? */
	return vfwprintf(stdout, format, ap);
}
