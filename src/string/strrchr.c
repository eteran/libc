
#define _ELIBC_SOURCE
#include <string.h>

/*------------------------------------------------------------------------------
// Name: strrchr
//----------------------------------------------------------------------------*/
char *strrchr(const char *s, int c) {
	char *retval = 0;

	do {
		if (*s == c) {
			retval = (char *)s;
		}
	} while (*s++ != '\0');

	return retval;
}
