
#define _ELIBC_SOURCE
#include <assert.h>
#include <string.h>

/*------------------------------------------------------------------------------
// Name: strchr
//----------------------------------------------------------------------------*/
char *strchr(const char *s, int c) {
	const char cmp = c;

	assert(s);

	while (*s != cmp) {
		if (*s == '\0') {
			return 0;
		}
		++s;
	}

	return (char *)s;
}
