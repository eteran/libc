
#define _ELIBC_SOURCE
#include <assert.h>
#include <string.h>

/**
 * @brief Transform a string into a form that can be compared
 *
 * @param dest the destination buffer where the transformed string will be stored
 * @param src the source string to be transformed
 * @param n the maximum number of characters to be written to the destination buffer
 * @return size_t the number of characters written to the destination buffer
 */
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
