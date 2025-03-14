
#define _ELIBC_SOURCE
#include <assert.h>
#include <wchar.h>

/**
 * @brief Calculates the length of the initial segment of a wide string that consists entirely of characters from a specified set
 *
 * @param s The wide string to be searched
 * @param accept The set of characters to be matched
 * @return size_t The length of the initial segment of s that consists entirely of characters from accept
 */
size_t wcsspn(const wchar_t *s, const wchar_t *accept) {
	const wchar_t *s_ptr = s;

	assert(s);
	assert(accept);

	while (*s_ptr != L'\0') {
		if (wcschr(accept, *s_ptr) == 0) {
			break;
		}

		++s_ptr;
	}

	return (size_t)(s_ptr - s);
}
