
#define __ELIBC_SOURCE
#include <stdarg.h>
#include <stdio.h>
#include <wchar.h>

/* TODO(eteran): implement this */

/*------------------------------------------------------------------------------
// Name:
//----------------------------------------------------------------------------*/
int vswprintf(wchar_t *wcs, size_t maxlen, const wchar_t *format, va_list args) {
	(void)wcs;
	(void)maxlen;
	(void)format;
	(void)args;
	return -1;
}
