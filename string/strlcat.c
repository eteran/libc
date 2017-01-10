
#define __ELIBC_SOURCE
#define __ELIBC_SAFE_STRING
#include <string.h>
#include <assert.h>

/*------------------------------------------------------------------------------
// Name: strlcat
//----------------------------------------------------------------------------*/
size_t strlcat(char *__ELIBC_RESTRICT dest, const char *__ELIBC_RESTRICT src, size_t siz) {

	char *d       = dest;
	const char *s = src;
	size_t n      = siz;
	size_t dlen;

	assert(dest);
	assert(src);

	/* Find the end of dest and adjust bytes left but don't go past end */
	while (n-- && *d != '\0') {
		d++;
	}

	dlen = d - dest;
	n    = siz - dlen;

	if (n == 0) {
		return(dlen + strlen(s));
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
	return dlen + (s - src);
}