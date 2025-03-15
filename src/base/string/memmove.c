
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

	assert(dest);
	assert(src);

	if (dest == src) {
		return dest;
	}

	if ((uintptr_t)dest > (uintptr_t)src) {
		/* copy backwards */
		char *dest_ptr      = dest;
		const char *src_ptr = src;

		while (n--) {
			dest_ptr[n] = src_ptr[n];
		}
		return dest;
	} else {
		/* copy normally */
		return memcpy(dest, src, n);
	}
}
