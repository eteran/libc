
#define _ELIBC_SOURCE
#include <string.h>

/**
 * @brief Find the first occurrence of any character from a specified set in a string
 *
 * @param s the string to be searched
 * @param accept the set of characters to be searched for
 * @return pointer to the first occurrence of any character from the specified set in the string, or NULL if none of the characters are found
 */
char *strpbrk(const char *s, const char *accept) {
	char *ret = 0;

	_LIBC_PRECOND(s);
	_LIBC_PRECOND(accept);

	while (*s != '\0') {
		if (strchr(accept, *s) != 0) {
			ret = (char *)s;
			break;
		}
		++s;
	}

	return ret;
}
