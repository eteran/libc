
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdint.h>
#include <string.h>

/**
 * @brief Compare the bytes of two blocks of memory
 *
 * @param s1 the first block of memory to compare
 * @param s2 the second block of memory to compare
 * @param n the number of bytes to compare
 * @return 0 if the blocks are equal, a negative value if s1 is less than s2, or a positive value if s1 is greater than s2
 */
int memcmp(const void *s1, const void *s2, size_t n) {

	int ret        = 0;
	const char *p1 = s1;
	const char *p2 = s2;

	assert(s1);
	assert(s2);

	while (!ret && n--) {
		ret = (*p1++ - *p2++);
	}

	return ret;
}
