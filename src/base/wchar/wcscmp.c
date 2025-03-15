
#define _ELIBC_SOURCE
#include <assert.h>
#include <wchar.h>

/**
 * @brief Compare two wide-character strings
 *
 * @param s1 The first wide-character string to be compared
 * @param s2 The second wide-character string to be compared
 * @return less than, equal to, or greater than zero if s1 is
 * lexicographically less than, equal to, or greater than s2.
 */
int wcscmp(const wchar_t *s1, const wchar_t *s2) {
	int ret = 0;

	assert(s1);
	assert(s2);

	while (!ret && (*s1 || *s2)) {
		ret = (*s1++ - *s2++);
	}

	return ret;
}
