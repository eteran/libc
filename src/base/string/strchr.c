
#define _ELIBC_SOURCE
#include <assert.h>
#include <string.h>

/**
 * @brief Find the first occurrence of a character in a string
 *
 * @param s the string to be searched
 * @param c the character to be searched for
 * @return a pointer to the first occurrence of the character in the string, or NULL if the character is not found
 */
char *strchr(const char *s, int c) {
	const unsigned char cmp = (unsigned char)c;

	assert(s);

	while ((unsigned char)*s != cmp) {
		if (*s == '\0') {
			return 0;
		}
		++s;
	}

	return (char *)s;
}
