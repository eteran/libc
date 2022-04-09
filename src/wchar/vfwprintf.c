
#define _ELIBC_SOURCE
#include <stdarg.h>
#include <stdio.h>
#include <wchar.h>

/* TODO(eteran): implement this */

/*------------------------------------------------------------------------------
// Name:
//----------------------------------------------------------------------------*/
int vfwprintf(FILE *stream, const wchar_t *format, va_list args) {
	(void)stream;
	(void)format;
	(void)args;
	return -1;
}
