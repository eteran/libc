
#define _ELIBC_SOURCE
#include <assert.h>
#include <string.h>

/**
 * @brief Compare two strings
 *
 * @param s1 the first string to be compared
 * @param s2 the second string to be compared
 * @return int a negative value if s1 is less than s2, a positive value if s1 is greater than s2, and 0 if they are equal
 */
int strcmp(const char *s1, const char *s2) {
	int ret = 0;

	assert(s1);
	assert(s2);

	while (!ret && (*s1 || *s2)) {
		ret = ((unsigned char)*s1++ - (unsigned char)*s2++);
	}

	return ret;
}
