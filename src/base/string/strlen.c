
#define _ELIBC_SOURCE
#include <assert.h>
#include <string.h>

/**
 * @brief Find the length of a string
 *
 * @param s the string to be measured
 * @return size_t the length of the string, not including the null terminator
 */
size_t strlen(const char *s) {
	const char *s_ptr = s;

	assert(s);

	while (*s != '\0') {
		++s;
	}

	return (size_t)(s - s_ptr);
}
