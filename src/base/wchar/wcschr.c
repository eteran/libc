
#define _ELIBC_SOURCE
#include <wchar.h>

/**
 * @brief Locate the first occurrence of a wide-character in a wide-character string
 *
 * @param s the wide-character string to be scanned
 * @param c the wide-character to be located
 * @return wchar_t* pointer to the first occurrence in s of the wide-character c
 * or NULL if the wide-character is not found
 */
wchar_t *wcschr(const wchar_t *s, wchar_t c) {
	const wchar_t cmp = c;

	while (*s != L'\0') {
		if (*s == cmp) {
			return (wchar_t *)s;
		}
		++s;
	}

	return 0;
}
