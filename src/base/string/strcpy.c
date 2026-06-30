
#define _ELIBC_SOURCE
#include <string.h>

/**
 * @brief Copy a string from source to destination
 *
 * @param dest the destination buffer
 * @param src the source string
 * @return pointer to the destination buffer
 */
char *strcpy(char *_RESTRICT dest, const char *_RESTRICT src) {
	char *dest_ptr = dest;

	_LIBC_PRECOND(dest);
	_LIBC_PRECOND(src);

	while (*src != '\0') {
		*dest_ptr++ = *src++;
	}

	*dest_ptr = '\0';
	return dest;
}
