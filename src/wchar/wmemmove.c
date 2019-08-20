
#define __ELIBC_SOURCE
#include <wchar.h>
#include <assert.h>

/*------------------------------------------------------------------------------
// Name: wmemmove
//----------------------------------------------------------------------------*/
wchar_t *wmemmove(wchar_t *dest, const wchar_t *src, size_t n) {

	assert(dest);
	assert(src);

	if(dest > src) {
		/* copy backwards */
		wchar_t *dest_ptr      = dest;
		const wchar_t *src_ptr = src;

		while(n--) {
			dest_ptr[n] = src_ptr[n];
		}
		return dest;
	} else {
		/* copy normally */
		return wmemcpy(dest, src, n);
	}
}
