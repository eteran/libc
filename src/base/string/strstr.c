
#define _ELIBC_SOURCE
#include <assert.h>
#include <string.h>

/**
 * @brief Find the first occurrence of a substring in a string
 *
 * @param haystack the string to be searched
 * @param needle the substring to be searched for
 * @param n the maximum number of characters to be searched
 * @return pointer to the first occurrence of the substring in the string, or NULL if the substring is not found
 */
char *strnstr(const char *haystack, const char *needle, size_t n) {
	const char *h_ptr;
	size_t needle_len;
	size_t i;

	assert(needle);
	assert(haystack);

	if (*needle == '\0') {
		return (char *)haystack;
	}

	needle_len = strlen(needle);
	if (n < needle_len) {
		return 0;
	}

	h_ptr = haystack;
	for (i = 0; i + needle_len <= n && h_ptr[i] != '\0'; ++i) {
		if (h_ptr[i] == needle[0] && memcmp(h_ptr + i, needle, needle_len) == 0) {
			return (char *)(h_ptr + i);
		}
	}

	return 0;
}

/**
 * @brief Find the first occurrence of a substring in a string
 *
 * @param haystack the string to be searched
 * @param needle the substring to be searched for
 * @return pointer to the first occurrence of the substring in the string, or NULL if the substring is not found
 */
char *strstr(const char *haystack, const char *needle) {
	return strnstr(haystack, needle, strlen(haystack));
}
