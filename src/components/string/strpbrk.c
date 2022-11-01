
#define _ELIBC_SOURCE
#include <string.h>

/*------------------------------------------------------------------------------
// Name: strpbrk
//----------------------------------------------------------------------------*/
char *strpbrk(const char *s, const char *accept) {
	char *ret = 0;

	while (*s != '\0') {
		if (strchr(accept, *s) != 0) {
			ret = (char *)s;
			break;
		}
		++s;
	}

	return ret;
}
