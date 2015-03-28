
#define __ELIBC_SOURCE
#include <stdio.h>
#include <assert.h>

/*------------------------------------------------------------------------------
// Name: fsetpos
//----------------------------------------------------------------------------*/
int fsetpos(FILE *stream, const fpos_t *pos) {

	assert(stream);
	assert(pos);

	/* TODO: catch any errors */
	fseek(stream, *pos, SEEK_SET);
	return 0;
}
