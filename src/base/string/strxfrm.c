
#define _ELIBC_SOURCE
#include <assert.h>
#include <string.h>

/**
 * @brief Transform a string into a form that can be compared
 *
 * @param dest the destination buffer where the transformed string will be stored
 * @param src the source string to be transformed
 * @param n the maximum number of characters to be written to the destination buffer
 * @return the number of characters written to the destination buffer
 */
size_t strxfrm(char *_RESTRICT dest, const char *_RESTRICT src, size_t n) {

	/* TODO(eteran): be locale aware */
	size_t src_len;
	assert(src);

	src_len = strlen(src);

	if (n != 0) {
		size_t copy_len;
		assert(dest);
		copy_len = (src_len < (n - 1)) ? src_len : (n - 1);
		memcpy(dest, src, copy_len);
		dest[copy_len] = '\0';
	}
	return src_len;
}
