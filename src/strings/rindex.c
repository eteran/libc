
#define _ELIBC_SOURCE
#include <string.h>
#include <strings.h>

/*------------------------------------------------------------------------------
// Name: rindex
//----------------------------------------------------------------------------*/
char *rindex(const char *s, int c) {
	if (c == '\0') {
		return (char *)s + strlen(s);
	}

	return strrchr(s, c);
}
