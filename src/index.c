
#define __ELIBC_SOURCE
#include <strings.h>
#include <string.h>

/*------------------------------------------------------------------------------
// Name: index
//----------------------------------------------------------------------------*/
char *index(const char *s, int c) {
	if(c == '\0') {
		return (char*)s + strlen(s);
	}

	return strchr(s, c);
}
