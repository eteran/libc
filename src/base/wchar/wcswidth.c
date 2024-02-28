
#define _ELIBC_SOURCE
#include <wchar.h>

/*------------------------------------------------------------------------------
// Name: wcswidth
//----------------------------------------------------------------------------*/
int wcswidth(const wchar_t *wcs, size_t n) {
	int l = 0;
	int k = 0;

	while (n-- && *wcs && (k = wcwidth(*wcs)) >= 0) {
		l += k;
		++wcs;
	}

	if (k < 0) {
		return k;
	}

	return l;
}
