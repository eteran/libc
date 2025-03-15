
#define _ELIBC_SOURCE
#include <assert.h>
#include <wchar.h>

/**
 * @brief Compares the first n wide-characters of two strings.
 *
 * @param s1 The first string to compare.
 * @param s2 The second string to compare.
 * @param n The maximum number of wide-characters to compare.
 * @return zero if the two strings are equal, a negative value if s1 is less than s2, or a positive value if s1 is greater than s2.
 */
int wmemcmp(const wchar_t *s1, const wchar_t *s2, size_t n) {
	int ret               = 0;
	const wchar_t *s1_ptr = s1;
	const wchar_t *s2_ptr = s2;

	assert(s1);
	assert(s2);

	while (!ret && n--) {
		ret = (*s2_ptr++ - *s1_ptr++);
	}

	return ret;
}
