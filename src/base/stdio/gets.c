
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdio.h>

/**
 * @brief Read a string from standard input
 *
 * @param s a pointer to the buffer to read the string into
 * @return a pointer to the buffer containing the string read from standard input
 * @warning This function is unsafe and should not be used in new code. It is provided for compatibility with legacy code.
 * @see fgets
 */
char *gets(char *s) {
	char *s_ptr = s;

	assert(s);

	while (1) {
		const int ch = getchar();
		if (ch == '\n' || ch == EOF) {
			break;
		}
		*s_ptr++ = (char)ch;
	}

	*s_ptr = '\0';

	return s;
}
