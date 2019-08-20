
#define __ELIBC_SOURCE
#include <strings.h>
#include <string.h>

/*------------------------------------------------------------------------------
// Name: rindex
//----------------------------------------------------------------------------*/
char *rindex(const char *s, int c) {
	if(c == '\0') {
		return (char *)s + strlen(s);
	}

	return strrchr(s, c);
}
