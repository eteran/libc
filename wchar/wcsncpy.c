
#define __ELIBC_SOURCE
#include <wchar.h>

/*------------------------------------------------------------------------------
// Name: wcsncpy
//----------------------------------------------------------------------------*/
wchar_t *wcsncpy(wchar_t *__ELIBC_RESTRICT dest, const wchar_t *__ELIBC_RESTRICT src, size_t n) {

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
