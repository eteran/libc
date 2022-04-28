
#define _ELIBC_SOURCE
#include <assert.h>
#include <string.h>

/*------------------------------------------------------------------------------
// Name: strxfrm
//----------------------------------------------------------------------------*/
size_t strxfrm(char *_RESTRICT dest, const char *_RESTRICT src, size_t n) {

	/* TODO(eteran): be locale aware */
	size_t count = 0;
	assert(src);

	if (n != 0) {
		size_t i;
		assert(dest);
		for (i = 0; i < n - 1; ++i) {
			*dest++ = *src++;
			++count;
			if (!*src) {
				break;
			}
		}

		*dest = '\0';
	}
	return count;
}
