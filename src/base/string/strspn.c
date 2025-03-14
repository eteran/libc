
#define _ELIBC_SOURCE
#include <assert.h>
#include <string.h>

/**
 * @brief Find the length of the initial segment of a string that consists entirely of characters from a specified set
 *
 * @param s the string to be searched
 * @param accept the set of characters to be searched for
 * @return size_t the length of the initial segment of the string that consists entirely of characters from the specified set
 */
size_t strspn(const char *s, const char *accept) {
	const char *s_ptr = s;

	assert(s);
	assert(accept);

	while (*s_ptr != '\0') {
		if (strchr(accept, *s_ptr) == 0) {
			break;
		}

		++s_ptr;
	}

	return (size_t)(s_ptr - s);
}
