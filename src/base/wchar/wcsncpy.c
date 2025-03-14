
#define _ELIBC_SOURCE
#include <wchar.h>

/**
 * @brief Copy a wide-character string
 *
 * @param dest destination wide-character string
 * @param src source wide-character string
 * @param n maximum number of characters to be copied
 * @return wchar_t* pointer to the destination string dest
 */
wchar_t *wcsncpy(wchar_t *_RESTRICT dest, const wchar_t *_RESTRICT src, size_t n) {

	wchar_t *dest_ptr = dest;

	while (n && (*src != L'\0')) {
		*dest_ptr++ = *src++;
		--n;
	}

	while (n--) {
		*dest_ptr++ = L'\0';
	}

	return dest;
}
