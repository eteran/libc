
#define _ELIBC_SOURCE
#include <wchar.h>

/*------------------------------------------------------------------------------
// Name: wcsrtombs
//----------------------------------------------------------------------------*/
size_t wcsrtombs(char *dest, const wchar_t **src, size_t len, mbstate_t *ps) {
	_UNUSED(dest);
	_UNUSED(src);
	_UNUSED(len);
	_UNUSED(ps);
	return 0;
}
