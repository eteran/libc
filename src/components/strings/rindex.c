
#define _ELIBC_SOURCE
#include <string.h>
#include <strings.h>

/*------------------------------------------------------------------------------
// Name: rindex
//----------------------------------------------------------------------------*/
char *rindex(const char *s, int c) {
	return strrchr(s, c);
}
