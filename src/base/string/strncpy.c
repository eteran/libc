
#define _ELIBC_SOURCE
#include <string.h>

/**
 * @brief Copy a string up to a specified number of characters
 *
 * @param dest the destination string
 * @param src the source string
 * @param n the maximum number of characters to be copied from the source string
 * @note If the length of the source string is less than n, the destination string will be padded with null characters
 * @note If the length of the source string is greater than or equal to n, the destination string will not be null-terminated
 * @return char* pointer to the destination string
 */
char *strncpy(char *_RESTRICT dest, const char *_RESTRICT src, size_t n) {

	char *dest_ptr = dest;

	while (n && (*src != '\0')) {
		*dest_ptr++ = *src++;
		--n;
	}

	while (n--) {
		*dest_ptr++ = '\0';
	}

	return dest;
}
