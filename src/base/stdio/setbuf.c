
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdio.h>

/*------------------------------------------------------------------------------
// Name: setbuf
//----------------------------------------------------------------------------*/
void setbuf(FILE *_RESTRICT stream, char *_RESTRICT buf) {
	assert(stream);
	setvbuf(stream, buf, buf ? _IOFBF : _IONBF, BUFSIZ);
}
