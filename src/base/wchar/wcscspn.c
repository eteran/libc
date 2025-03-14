
#define _ELIBC_SOURCE
#include <assert.h>
#include <wchar.h>

/**
 * @brief Calculate the length of the initial segment of a wide-character
 *
 * @param s the wide-character string to be scanned
 * @param reject the wide-character string containing the characters to be rejected
 * @return size_t number of wide-characters in the initial segment of s that consist
 * only of characters not in reject
 */
size_t wcscspn(const wchar_t *s, const wchar_t *reject) {
	const wchar_t *s_ptr = s;

	assert(s);
	assert(reject);

	while (*s_ptr != L'\0') {
		if (wcschr(reject, *s_ptr) != 0) {
			break;
		}

		++s_ptr;
	}

	return (size_t)(s_ptr - s);
}
