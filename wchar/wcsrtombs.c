
#define __ELIBC_SOURCE
#include <wchar.h>

/*------------------------------------------------------------------------------
// Name: wcsrtombs
//----------------------------------------------------------------------------*/
size_t wcsrtombs(char *dest, const wchar_t **src, size_t len, mbstate_t *ps) {
	(void)dest;
	(void)src;
	(void)len;
	(void)ps;
	return -1;
}
