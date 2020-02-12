
#define __ELIBC_SOURCE
#include <string.h>

/*------------------------------------------------------------------------------
// Name: strrchr
//----------------------------------------------------------------------------*/
char *strrchr(const char *s, int c) {
	const char *ret = 0;
	const char cmp  = (char)(c & 0xff);

	while (*s != '\0') {
		if (*s == cmp) {
			ret = s;
		}
		++s;
	}

	return (char *)ret;
}
