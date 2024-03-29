
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdio.h>

/*------------------------------------------------------------------------------
// Name: fgetpos
//----------------------------------------------------------------------------*/
int fgetpos(FILE *stream, fpos_t *pos) {

	long ret;

	assert(stream);
	assert(pos);

	ret = ftell(stream);

	if (ret != -1) {
		pos->offset = ret;
		ret         = 0;
	}

	return (int)ret;
}
