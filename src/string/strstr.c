
#define _ELIBC_SOURCE
#include <string.h>

/*------------------------------------------------------------------------------
// Name: strnstr
//----------------------------------------------------------------------------*/
char *strnstr(const char *haystack, const char *needle, size_t n) {

	if (needle[0] == '\0') {
		return (char *)haystack;
	} else {
		while (*haystack != '\0') {
			if (strncmp(haystack, needle, n) == 0) {
				return (char *)haystack;
			}
			++haystack;
		}
	}

	return 0;
}

/*------------------------------------------------------------------------------
// Name: strstr
//----------------------------------------------------------------------------*/
char *strstr(const char *haystack, const char *needle) {
	return strnstr(haystack, needle, strlen(needle));
}
