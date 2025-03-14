
#define _ELIBC_SOURCE
#include <string.h>

/**
 * @brief Concatenate two strings up to a specified number of characters
 *
 * @param dest the destination string
 * @param src the source string
 * @param n the maximum number of characters to be copied from the source string
 * @return char* pointer to the destination string
 */
char *strncat(char *_RESTRICT dest, const char *_RESTRICT src, size_t n) {
	char *dest_ptr = dest;

	if (n != 0) {
		/* find the end of the string... */
		while (*dest_ptr != '\0') {
			++dest_ptr;
		}

		/* copy the new string to that location */
		while (n-- && *src != '\0') {
			*dest_ptr++ = *src++;
		}

		*dest_ptr = '\0';
	}

	/* return pointer to combined string */
	return dest;
}
