
#define _ELIBC_SOURCE
#include <assert.h>
#include <ctype.h>
#include <strings.h>

/**
 * @brief Compare two strings ignoring case up to n characters
 *
 * @param s1 the first string to compare
 * @param s2 the second string to compare
 * @param n the maximum number of characters to compare
 * @return a negative value if s1 is less than s2, a positive value if s1 is greater than s2, and 0 if they are equal
 */
int strncasecmp(const char *s1, const char *s2, size_t n) {
	int ret = 0;

	assert(s1);
	assert(s2);

	while (!ret && (*s1 || *s2) && n--) {
		const char cs1 = (char)tolower(*s1++);
		const char cs2 = (char)tolower(*s2++);
		ret            = (cs1 - cs2);
	}

	return ret;
}
