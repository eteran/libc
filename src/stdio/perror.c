
#define __ELIBC_SOURCE
#include <errno.h>
#include <stdio.h>
#include <string.h>

/*------------------------------------------------------------------------------
// Name: perror
//----------------------------------------------------------------------------*/
void perror(const char *s) {
	if (s) {
		fputs(s, stderr);
	}

	fputs(": ", stderr);
	fputs(strerror(errno), stderr);
}
