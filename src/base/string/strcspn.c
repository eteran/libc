
#define _ELIBC_SOURCE
#include <assert.h>
#include <string.h>

/**
 * @brief Find the length of the initial segment of a string that does not contain any characters from a specified set
 *
 * @param s the string to be searched
 * @param reject the set of characters to be rejected
 * @return size_t the length of the initial segment of the string that does not contain any characters from the reject set
 */
size_t strcspn(const char *s, const char *reject) {
	const char *s_ptr = s;

	assert(s);
	assert(reject);

	while (*s_ptr != '\0') {
		if (strchr(reject, *s_ptr) != 0) {
			break;
		}

		++s_ptr;
	}

	return (size_t)(s_ptr - s);
}
