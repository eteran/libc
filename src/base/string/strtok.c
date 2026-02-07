
#define _ELIBC_SOURCE
#include <string.h>

/**
 * @brief Split a string into tokens
 *
 * @param s the string to be split
 * @param delim the delimiter characters
 * @return pointer to the next token in the string, or NULL if there are no more tokens
 * @note This function is not thread-safe. Use strtok_r instead.
 */
char *strtok(char *_RESTRICT s, const char *_RESTRICT delim) {
	static _Thread_local char *ptr = 0;
	return strtok_r(s, delim, &ptr);
}

/**
 * @brief Split a string into tokens (thread-safe)
 *
 * @param s the string to be split
 * @param delim the delimiter characters
 * @param saveptr pointer to a char* where the function will store the next position in the string
 * @return pointer to the next token in the string, or NULL if there are no more tokens
 */
char *strtok_r(char *_RESTRICT s, const char *_RESTRICT delim, char **saveptr) {

	char *start;
	char *end;

	if (s) {
		/* if s != 0 then we consider this the "first call" */
		*saveptr = s;
	}

	start = *saveptr;
	if (!start) {
		return 0;
	}

	/* skip first delimiters */
	start += strspn(start, delim);

	if (*start == '\0') {
		*saveptr = 0;
		return 0;
	}

	/* find the end of this token */
	end = strpbrk(start + 1, delim);

	/* if it did not end at the end of the string, replace
	   that delimiter with a NULL terminator */
	if (end) {
		*end++ = '\0';
	}
	*saveptr = end;
	return start;
}
