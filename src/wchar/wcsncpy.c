
#define __ELIBC_SOURCE
#include <wchar.h>

/*------------------------------------------------------------------------------
// Name: wcsncpy
//----------------------------------------------------------------------------*/
wchar_t *wcsncpy(wchar_t *_RESTRICT dest, const wchar_t *_RESTRICT src, size_t n) {

	wchar_t *dest_ptr = dest;

	while(n && (*src != '\0')) {
		*dest_ptr++ = *src++;
		--n;
	}

	while(n--) {
		*dest_ptr++ = '\0';
	}

	return dest;

}
