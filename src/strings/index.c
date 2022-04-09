
#define _ELIBC_SOURCE
#include <string.h>
#include <strings.h>

/*------------------------------------------------------------------------------
// Name: index
//----------------------------------------------------------------------------*/
char *index(const char *s, int c) {
	if (c == '\0') {
		return (char *)s + strlen(s);
	}

	return strchr(s, c);
}
