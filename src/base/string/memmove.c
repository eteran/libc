
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdint.h>
#include <string.h>

/**
 * @brief Copy a block of memory from one location to another, even if the two
 * locations overlap.
 *
 * @param dest a pointer to the destination of the copy
 * @param src a pointer to the source of the copy
 * @param n the number of bytes to copy
 * @return a pointer to the destination of the copy
 */
void *memmove(void *dest, const void *src, size_t n) {

	unsigned char *dest_ptr;
	const unsigned char *src_ptr;
	size_t i;

	if (n == 0) {
		return dest;
	}

	assert(dest);
	assert(src);

	if (dest == src) {
		return dest;
	}

	dest_ptr = dest;
	src_ptr  = src;

	if ((uintptr_t)dest_ptr > (uintptr_t)src_ptr) {
		/* copy backwards */
		for (i = n; i > 0; --i) {
			dest_ptr[i - 1] = src_ptr[i - 1];
		}
		return dest;
	}

	/* copy forwards */
	for (i = 0; i < n; ++i) {
		dest_ptr[i] = src_ptr[i];
	}
	return dest;
}
