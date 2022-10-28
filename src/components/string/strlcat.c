
#define _ELIBC_SOURCE
#define _ELIBC_SAFE_STRING
#include <assert.h>
#include <string.h>

/*------------------------------------------------------------------------------
// Name: strlcat
//----------------------------------------------------------------------------*/
size_t strlcat(char *_RESTRICT dest, const char *_RESTRICT src, size_t siz) {

	char *d = dest;
	const char *s = src;
	size_t n = siz;
	size_t dlen;

	assert(dest);
	assert(src);

	/* Find the end of dest and adjust bytes left but don't go past end */
	while (n-- && *d != '\0') {
		d++;
	}

	dlen = (size_t)(d - dest);
	n = siz - dlen;

	if (n == 0) {
		return (dlen + strlen(s));
	}

	while (*s != '\0') {
		if (n != 1) {
			*d++ = *s;
			n--;
		}
		s++;
	}

	*d = '\0';

	/* count does not include '\0' */
	return dlen + (size_t)(s - src);
}
