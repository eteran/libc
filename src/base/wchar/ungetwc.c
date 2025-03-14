
#define _ELIBC_SOURCE
#include <stdio.h>
#include <wchar.h>

/**
 * @brief Push a wide-character back onto a stream
 *
 * @param wc the wide-character to be pushed back
 * @param stream the stream to push the character back onto
 * @return wint_t the pushed back character, or WEOF if an error occurred
 */
wint_t ungetwc(wint_t wc, FILE *stream) {
	_UNUSED(wc);
	_UNUSED(stream);

	/* TODO(eteran): implement this */
	return WEOF;
}
