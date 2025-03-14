
#define _ELIBC_SOURCE
#include <assert.h>
#include <string.h>
#include <strings.h>

/**
 * @brief Compare two blocks of memory
 *
 * @param s1 the first block of memory to compare
 * @param s2 the second block of memory to compare
 * @param n the number of bytes to compare
 * @return int a negative value if s1 is less than s2, a positive value if s1 is greater than s2, and 0 if they are equal
 * @note This function is similar to memcmp, but it is not a standard C function.
 *       It is included for compatibility with other systems.
 */
int bcmp(const void *s1, const void *s2, size_t n) {
	assert(s1);
	assert(s2);
	return memcmp(s1, s2, n);
}
