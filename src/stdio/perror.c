
#define __ELIBC_SOURCE
#include <stdio.h>
#include <errno.h>
#include <string.h>

/*------------------------------------------------------------------------------
// Name: perror
//----------------------------------------------------------------------------*/
void perror(const char *s) {
	if(s) {
		fputs(s, stderr);
	}

	fputs(": ", stderr);
	fputs(strerror(errno), stderr);
}
