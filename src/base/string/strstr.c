
#define _ELIBC_SOURCE
#include <assert.h>
#include <string.h>

/*------------------------------------------------------------------------------
// Name: strnstr
//----------------------------------------------------------------------------*/
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

/*------------------------------------------------------------------------------
// Name: strstr
//----------------------------------------------------------------------------*/
char *strstr(const char *haystack, const char *needle) {
	return strnstr(haystack, needle, strlen(needle));
}
