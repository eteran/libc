
#define _ELIBC_SOURCE
#include <assert.h>
#include <string.h>

/**
 * @brief Search for the first occurrence of a character in a block of memory
 *
 * @param s a pointer to the block of memory to search
 * @param c the character to search for
 * @param n the number of bytes to search
 * @return a pointer to the first occurrence of the character in the block of memory, or NULL if the character is not found
 */
void *memchr(const void *s, int c, size_t n) {

	const unsigned char *s_ptr;
	const unsigned char cmp = (unsigned char)c;

	if (n == 0) {
		return 0;
	}

	assert(s);

	s_ptr = s;

	while (n--) {
		if (*s_ptr == cmp) {
			return (void *)s_ptr;
		}
		++s_ptr;
	}

	return 0;
}
