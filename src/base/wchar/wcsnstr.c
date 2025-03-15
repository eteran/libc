
#define _ELIBC_SOURCE
#include <wchar.h>

/**
 * @brief Searches for the first occurrence of a wide string in another wide string
 *
 * @param haystack The wide string to search in
 * @param needle The wide string to search for
 * @param n The maximum number of characters to search for
 * @return A pointer to the first occurrence of needle in haystack, or NULL if needle is not found
 */
wchar_t *wcsnstr(const wchar_t *haystack, const wchar_t *needle, size_t n) {

	if (needle[0] == L'\0') {
		return (wchar_t *)haystack;
	} else {
		while (*haystack != L'\0') {
			if (wcsncmp(haystack, needle, n) == 0) {
				return (wchar_t *)haystack;
			}
			++haystack;
		}
	}

	return 0;
}
