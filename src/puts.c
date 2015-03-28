
#define __ELIBC_SOURCE
#include <stdio.h>
#include <assert.h>

/*------------------------------------------------------------------------------
// Name: puts
//----------------------------------------------------------------------------*/
int puts(const char *s) {

	assert(s);

	while(*s != '\0') {
		if(putchar(*s++) == EOF) {
			return EOF;
		}
	}

	return putchar('\n');
}
