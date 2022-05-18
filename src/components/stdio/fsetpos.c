
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdio.h>

/*------------------------------------------------------------------------------
// Name: fsetpos
//----------------------------------------------------------------------------*/
int fsetpos(FILE *stream, const fpos_t *pos) {

	assert(stream);
	assert(pos);

	/* TODO(eteran): catch any errors */
	fseek(stream, *pos, SEEK_SET);
	return 0;
}
