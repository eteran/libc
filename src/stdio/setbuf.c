
#define __ELIBC_SOURCE
#include <stdio.h>
#include <assert.h>

/*------------------------------------------------------------------------------
// Name: setbuf
//----------------------------------------------------------------------------*/
void setbuf(FILE *_RESTRICT stream, char *_RESTRICT buf) {
	assert(stream);
	setvbuf(stream, buf, buf ? _IOFBF : _IONBF, BUFSIZ);
}
