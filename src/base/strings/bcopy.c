
#define _ELIBC_SOURCE
#include <assert.h>
#include <string.h>
#include <strings.h>

/**
 * @brief Copy a block of memory from one location to another
 *
 * @param src the source memory location
 * @param dest the destination memory location
 * @param n the number of bytes to copy
 * @note This function is similar to memmove, but it is not a standard C function.
 *       It is included for compatibility with other systems.
 */
void bcopy(const void *src, void *dest, size_t n) {
	assert(src);
	assert(dest);

	/* we use memmove because spec for bcopy says it is correct
	   even for overlapping regions */
	memmove(dest, src, n);
}
