
#define _ELIBC_SOURCE
#include <errno.h>
#include <stdio.h>
#include <string.h>

/**
 * @brief Write an error message to stderr
 *
 * @param s a pointer to the string to write, or NULL
 */
void perror(const char *s) {
	if (s) {
		fputs(s, stderr);
	}

	fputs(": ", stderr);
	fputs(strerror(errno), stderr);
}
