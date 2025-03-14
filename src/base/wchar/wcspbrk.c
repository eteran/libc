
#define _ELIBC_SOURCE
#include <wchar.h>

/**
 * @brief Scan a wide-character string for a character in another string
 *
 * @param s the wide-character string to be scanned
 * @param accept the wide-character string containing the characters to match
 * @return wchar_t* pointer to the first occurrence in s of any character
 * in accept, or NULL if no such character is found
 */
wchar_t *wcspbrk(const wchar_t *s, const wchar_t *accept) {
	const wchar_t *ret = 0;

	while (*s != L'\0') {
		if (wcschr(accept, *s) != 0) {
			ret = s;
			break;
		}
		++s;
	}

	return (wchar_t *)ret;
}
