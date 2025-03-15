
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdio.h>

/**
 * @brief Write a string to standard output, followed by a newline.
 *
 * @param s a pointer to the string to write
 * @return the number of characters written, or EOF on error
 */
int puts(const char *s) {

	assert(s);

	while (*s != '\0') {
		if (putchar(*s++) == EOF) {
			return EOF;
		}
	}

	return putchar('\n');
}
