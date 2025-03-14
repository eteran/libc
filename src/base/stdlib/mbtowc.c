
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdlib.h>
#include <wchar.h>

/**
 * @brief Convert a multibyte character to a wide character
 *
 * @param pwc a pointer to the destination wide-character buffer
 * @param s a pointer to the multibyte character to be converted
 * @param n the maximum number of bytes to write to the destination buffer
 * @return int the number of bytes written to pwc, or -1 on error
 */
int mbtowc(wchar_t *_RESTRICT pwc, const char *_RESTRICT s, size_t n) {
	static _Thread_local mbstate_t state;
	return (int)mbrtowc(pwc, s, n, &state);
}
