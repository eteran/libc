
#define _ELIBC_SOURCE
#include <stdio.h>
#include <wchar.h>

/**
 * @brief Read a wide-character string from a stream
 *
 * @param ws the wide-character string to be read
 * @param n maximum number of wide characters to be read
 * @param stream the input stream to read from
 * @return wchar_t* pointer to the wide-character string ws, or NULL if an error occurred
 * or the end of the stream was reached before any characters were read.
 */
wchar_t *fgetws(wchar_t *ws, int n, FILE *stream) {
	_UNUSED(ws);
	_UNUSED(n);
	_UNUSED(stream);

	/* TODO(eteran): implement this */
	return 0;
}
