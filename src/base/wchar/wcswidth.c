
#define _ELIBC_SOURCE
#include <wchar.h>

/**
 * @brief Returns the number of columns required to represent a wide string
 *
 * @param wcs The wide string to measure
 * @param n The maximum number of characters to measure
 * @return The number of columns required to represent the wide string, or -1 if the string contains an invalid character
 */
int wcswidth(const wchar_t *wcs, size_t n) {
	int l = 0;
	int k = 0;

	while (n-- && *wcs && (k = wcwidth(*wcs)) >= 0) {
		l += k;
		++wcs;
	}

	if (k < 0) {
		return k;
	}

	return l;
}
