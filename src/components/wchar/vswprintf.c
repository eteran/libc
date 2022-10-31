
#define _ELIBC_SOURCE
#include <stdarg.h>
#include <stdio.h>
#include <wchar.h>

/* TODO(eteran): implement this */

/*------------------------------------------------------------------------------
// Name:
//----------------------------------------------------------------------------*/
int vswprintf(wchar_t *wcs, size_t maxlen, const wchar_t *format, va_list args) {
	_UNUSED(wcs);
	_UNUSED(maxlen);
	_UNUSED(format);
	_UNUSED(args);
	return -1;
}
