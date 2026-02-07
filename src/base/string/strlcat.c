
#define _ELIBC_SOURCE
#define _ELIBC_SAFE_STRING
#include <assert.h>
#include <string.h>

/**
 * @brief Concatenate two strings up to a specified number of characters
 *
 * @param dest the destination string
 * @param src the source string
 * @param siz the size of the destination buffer
 * @return the length of the concatenated string
 * @note This function is not a standard C function. It is included for compatibility with other systems.
 */
size_t strlcat(char *_RESTRICT dest, const char *_RESTRICT src, size_t siz) {

	char *d       = dest;
	const char *s = src;
	size_t n      = siz;
	size_t dlen;

	assert(src);
	if (siz == 0) {
		return strlen(s);
	}

	assert(dest);

	/* Find the end of dest and adjust bytes left but don't go past end */
	while (n-- && *d != '\0') {
		d++;
	}

	dlen = (size_t)(d - dest);
	n    = siz - dlen;

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
