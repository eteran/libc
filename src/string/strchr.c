
#define _ELIBC_SOURCE
#include <string.h>

/*------------------------------------------------------------------------------
// Name: strchr
//----------------------------------------------------------------------------*/
char *strchr(const char *s, int c) {
	const char cmp = c;

	while (*s != '\0') {
		if (*s == cmp) {
			return (char *)s;
		}
		++s;
	}
	return 0;
}
