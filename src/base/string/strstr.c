
#define _ELIBC_SOURCE
#include <assert.h>
#include <string.h>

/**
 * @brief Find the first occurrence of a substring in a string
 *
 * @param haystack the string to be searched
 * @param needle the substring to be searched for
 * @param n the maximum number of characters to be searched
 * @return char* pointer to the first occurrence of the substring in the string, or NULL if the substring is not found
 */
char *strnstr(const char *haystack, const char *needle, size_t n) {

	assert(needle);
	assert(haystack);

	if (*needle == '\0') {
		return (char *)haystack;
	}

	while (*haystack != '\0') {
		if (strncmp(haystack, needle, n) == 0) {
			return (char *)haystack;
		}
		++haystack;
	}

	return 0;
}

/**
 * @brief Find the first occurrence of a substring in a string
 *
 * @param haystack the string to be searched
 * @param needle the substring to be searched for
 * @return char* pointer to the first occurrence of the substring in the string, or NULL if the substring is not found
 */
char *strstr(const char *haystack, const char *needle) {
	return strnstr(haystack, needle, strlen(needle));
}
