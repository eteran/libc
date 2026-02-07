
#define _ELIBC_SOURCE
#include <assert.h>
#include <string.h>

/**
 * @brief Find the last occurrence of a character in a string
 *
 * @param s the string to be searched
 * @param c the character to be searched for
 * @return pointer to the last occurrence of the character in the string, or NULL if the character is not found
 */
char *strrchr(const char *s, int c) {
	char *retval = 0;
	const unsigned char cmp = (unsigned char)c;

	assert(s);

	do {
		if ((unsigned char)*s == cmp) {
			retval = (char *)s;
		}
	} while (*s++ != '\0');

	return retval;
}
