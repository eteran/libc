
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdio.h>

/**
 * @brief Write a string to a stream (thread-unsafe)
 *
 * @param s a pointer to the string to write
 * @param stream the stream to write to
 * @return 0 on success, or EOF on error
 */
static int __elibc_fputs(const char *_RESTRICT s, FILE *_RESTRICT stream) {

	assert(s);
	assert(stream);

	while (*s != '\0') {
		if (__elibc_fputc(*s++, stream, _ELIBC_FILE_NARROW) == EOF) {
			return EOF;
		}
	}

	return 0;
}

/**
 * @brief Write a string to a stream
 *
 * @param s a pointer to the string to write
 * @param stream the stream to write to
 * @return 0 on success, or EOF on error
 */
int fputs(const char *_RESTRICT s, FILE *_RESTRICT stream) {
	int r;
	__ELIBC_WITH_LOCK(__elibc_fputs(s, stream), &r);
	return r;
}
