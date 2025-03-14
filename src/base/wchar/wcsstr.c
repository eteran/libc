
#define _ELIBC_SOURCE
#include <wchar.h>

/**
 * @brief Searches for the first occurrence of a wide string in another wide string
 *
 * @param haystack The wide string to search in
 * @param needle The wide string to search for
 * @return wchar_t* A pointer to the first occurrence of needle in haystack, or NULL if needle is not found
 */
wchar_t *wcsstr(const wchar_t *haystack, const wchar_t *needle) {
	return wcsnstr(haystack, needle, wcslen(needle));
}
