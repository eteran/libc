
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdio.h>

/**
 * @brief Read a string from a stream (thread-unsafe)
 *
 * @param s a pointer to the buffer to read the string into
 * @param size the maximum number of characters to read
 * @param stream the stream to read from
 * @return a pointer to the buffer containing the string, or NULL on error
 */
static char *__elibc_fgets(char *_RESTRICT s, int size, FILE *_RESTRICT stream) {
	char *s_ptr = s;

	if (size > 1) {
		while (--size) {
			const int ch = __elibc_fgetc(stream);

			if (ch != EOF) {
				*s_ptr++ = (char)ch;
			}

			if (ch == EOF && s_ptr == s) {
				/* TODO(eteran): NUL terminate this buffer? */
				return NULL;
			}

			if (ch == EOF || ch == '\n') {
				break;
			}
		}

		*s_ptr = '\0';
	}

	return s;
}

/**
 * @brief Read a string from a stream
 *
 * @param s a pointer to the buffer to read the string into
 * @param size the maximum number of characters to read
 * @param stream the stream to read from
 * @return a pointer to the buffer containing the string, or NULL on error
 */
char *fgets(char *_RESTRICT s, int size, FILE *_RESTRICT stream) {
	char *r;
	__ELIBC_WITH_LOCK(__elibc_fgets(s, size, stream), &r);
	return r;
}
