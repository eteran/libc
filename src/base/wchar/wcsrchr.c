
#define _ELIBC_SOURCE
#include <wchar.h>

/**
 * @brief Find the last occurrence of a wide-character in a wide string
 *
 * @param s The wide string to search
 * @param c The wide-character to search for
 * @return wchar_t* A pointer to the last occurrence of the wide-character in the wide string, or NULL if not found
 */
wchar_t *wcsrchr(const wchar_t *s, wchar_t c) {
	const wchar_t *ret = 0;
	const wchar_t cmp  = c;

	while (*s != L'\0') {
		if (*s == cmp) {
			ret = s;
		}
		++s;
	}

	return (wchar_t *)ret;
}
