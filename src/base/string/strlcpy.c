
#define _ELIBC_SOURCE
#define _ELIBC_SAFE_STRING
#include <assert.h>
#include <string.h>

/**
 * @brief Copy a string up to a specified number of characters
 *
 * @param dest the destination buffer
 * @param src the source string
 * @param n the size of the destination buffer
 * @return the length of the source string
 * @note This function is not a standard C function. It is included for compatibility with other systems.
 */
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
