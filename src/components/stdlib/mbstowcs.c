
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdlib.h>
#include <wchar.h>

/*------------------------------------------------------------------------------
// Name:
//----------------------------------------------------------------------------*/
size_t mbstowcs(wchar_t *dest, const char *src, size_t n) {

	static _Thread_local mbstate_t state = {0, 0, 0};

	const char *first = src;
	const char *last = src + n;
	wchar_t *out_ptr = dest;
	size_t rc;

	assert(src);

	while ((rc = mbrtowc(out_ptr, first, (size_t)(last - first), &state)) > 0) {
		first += rc;
		++out_ptr;
	}

	if (rc == (size_t)-1) {
		return rc;
	}

	return (size_t)(out_ptr - dest);
}
