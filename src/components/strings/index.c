
#define _ELIBC_SOURCE
#include <string.h>
#include <strings.h>

/*------------------------------------------------------------------------------
// Name: index
//----------------------------------------------------------------------------*/
char *index(const char *s, int c) {
	return strchr(s, c);
}
