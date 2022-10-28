
#define _ELIBC_SOURCE
#define _ELIBC_SAFE_STRING
#include <assert.h>
#include <string.h>

/*------------------------------------------------------------------------------
// Name: strlcpy
//----------------------------------------------------------------------------*/
size_t strlcpy(char *_RESTRICT dest, const char *_RESTRICT src, size_t n) {

	const char *const src_ptr = src;

	assert(dest);
	assert(src);

	/* iterate over source string */
	while (*src != '\0') {

		/* if we have room, add next char */
		if (n > 1) {
			*dest++ = *src++;
			--n;
		} else {
			/* no more copying, just looking for end of src.. */
			while (*++src != '\0') {
				;
			}
		}
	}

	/* this should only be false if they passed 0 to n */
	if (n != 0) {
		*dest = '\0';
	}

	return (size_t)(src - src_ptr);
}
