
#define _ELIBC_SOURCE
#include <wchar.h>

/**
 * @brief Transforms a wide string into a form suitable for comparison
 *
 * @param ws1 The destination wide string
 * @param ws2 The source wide string
 * @param n The maximum number of characters to write to ws1
 * @return size_t The number of characters transformed
 */
size_t wcsxfrm(wchar_t *_RESTRICT ws1, const wchar_t *_RESTRICT ws2, size_t n) {
	_UNUSED(ws1);
	_UNUSED(ws2);
	_UNUSED(n);

	/* TODO(eteran): implement this */
	return 0;
}
