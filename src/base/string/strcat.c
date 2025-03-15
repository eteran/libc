
#define _ELIBC_SOURCE
#include <assert.h>
#include <string.h>

/**
 * @brief Concatenate two strings
 *
 * @param dest the destination string
 * @param src the source string
 * @return pointer to the destination string
 */
char *strcat(char *_RESTRICT dest, const char *_RESTRICT src) {
	char *dest_ptr = dest;

	assert(dest);
	assert(src);

	/* find the end of the string... */
	while (*dest_ptr != '\0') {
		++dest_ptr;
	}

	/* copy the new string to that location */
	while (*src != '\0') {
		*dest_ptr++ = *src++;
	}

	*dest_ptr = '\0';

	/* return pointer to combined string */
	return dest;
}
