
#define __ELIBC_SOURCE
#include <stdio.h>
#include <assert.h>

/*------------------------------------------------------------------------------
// Name: setbuf
//----------------------------------------------------------------------------*/
void setbuf(FILE *__ELIBC_RESTRICT stream, char *__ELIBC_RESTRICT buf) {
	assert(stream);
	setvbuf(stream, buf, buf ? _IOFBF : _IONBF, BUFSIZ);
}
