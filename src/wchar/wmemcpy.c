
#define __ELIBC_SOURCE
#include <wchar.h>
#include <assert.h>

/*------------------------------------------------------------------------------
// Name: wmemcpy
//----------------------------------------------------------------------------*/
wchar_t *wmemcpy(wchar_t *_RESTRICT dest, const wchar_t *_RESTRICT src, size_t n) {

	/* traditional memory copy */
	wchar_t *d_ptr       = dest;
	const wchar_t *s_ptr = src;

	assert(dest);
	assert(src);

	while(n--) {
		*d_ptr++ = *s_ptr++;
	}

	return dest;
}
