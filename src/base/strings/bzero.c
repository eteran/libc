
#define _ELIBC_SOURCE
#include <assert.h>
#include <string.h>
#include <strings.h>

/**
 * @brief Set a block of memory to zero
 *
 * @param s pointer to the block of memory to be set to zero
 * @param n number of bytes to set to zero
 * @note This function is similar to memset(s, 0, n), but it is not a standard C function.
 *       It is included for compatibility with other systems.
 */
void bzero(void *s, size_t n) {
	assert(s);
	memset(s, 0, n);
}
