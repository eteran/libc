
#define _ELIBC_SOURCE
#include <assert.h>
#include <ctype.h>
#include <strings.h>

/**
 * @brief Compare two strings ignoring case
 *
 * @param s1 the first string to compare
 * @param s2 the second string to compare
 * @return int a negative value if s1 is less than s2, a positive value if s1 is greater than s2, and 0 if they are equal
 */
int strcasecmp(const char *s1, const char *s2) {
	int ret = 0;

	assert(s1);
	assert(s2);

	while (!ret && (*s1 || *s2)) {
		const char cs1 = (char)tolower(*s1++);
		const char cs2 = (char)tolower(*s2++);
		ret            = (cs1 - cs2);
	}

	return ret;
}
