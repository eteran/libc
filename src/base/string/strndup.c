
#define _ELIBC_SOURCE
#define _ELIBC_SAFE_STRING
#include <stdlib.h>
#include <string.h>

/**
 * @brief Duplicate a string up to a specified number of characters
 *
 * @param s the string to be duplicated
 * @param n the maximum number of characters to be copied from the string
 * @return char* pointer to the newly allocated string, or NULL if the allocation fails
 * @note This function is not a standard C function. It is included for compatibility with other systems.
 */
char *strndup(const char *s, size_t n) {
	const size_t len = (n + 1);
	char *const ret  = malloc(len);

	if (ret) {
		strncpy(ret, s, n);
		ret[len - 1] = '\0';
	}

	return ret;
}
