
#define _ELIBC_SOURCE
#include <assert.h>
#include <string.h>

/**
 * @brief Compare two strings up to a specified number of characters
 *
 * @param s1 the first string to be compared
 * @param s2 the second string to be compared
 * @param n the maximum number of characters to be compared
 * @return a negative value if s1 is less than s2, a positive value if s1 is greater than s2, or 0 if they are equal
 */
int strncmp(const char *s1, const char *s2, size_t n) {
	int ret = 0;

	if (n == 0) {
		return 0;
	}

	assert(s1);
	assert(s2);

	while (!ret && (*s1 || *s2) && n--) {
		ret = ((unsigned char)*s1++ - (unsigned char)*s2++);
	}

	return ret;
}
