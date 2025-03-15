
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdio.h>
#include <wchar.h>

/**
 * @brief Write a wide-character string to a stream (thread-unsafe)
 *
 * @param ws the wide-character string to be written
 * @param stream the output stream to write to
 * @return number of wide-characters written, not including the
 * terminating null wide-character, or EOF if an error occurred.
 */
static int __elibc_fputws(const wchar_t *ws, FILE *stream) {

	assert(ws);
	assert(stream);

	while (*ws != '\0') {
		if (__elibc_fputc(*ws++, stream, _ELIBC_FILE_WIDE) == EOF) {
			return EOF;
		}
	}

	return 0;
}

/**
 * @brief Write a wide-character string to a stream
 *
 * @param ws the wide-character string to be written
 * @param stream the output stream to write to
 * @return number of wide-characters written, not including the
 * terminating null wide-character, or EOF if an error occurred.
 */
int fputws(const wchar_t *ws, FILE *stream) {
	int r;
	__ELIBC_WITH_LOCK(__elibc_fputws(ws, stream), &r);
	return r;
}
