
#define _ELIBC_SOURCE
#include <string.h>

/*------------------------------------------------------------------------------
// Name: strpbrk
//----------------------------------------------------------------------------*/
char *strpbrk(const char *s, const char *accept) {
	const char *ret = 0;

	while (*s != '\0') {
		if (strchr(accept, *s) != 0) {
			ret = s;
			break;
		}
		++s;
	}

	return (char *)ret;
}
