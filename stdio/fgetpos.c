
#define __ELIBC_SOURCE
#include <stdio.h>
#include <assert.h>

/*------------------------------------------------------------------------------
// Name: fgetpos
//----------------------------------------------------------------------------*/
int fgetpos(FILE *stream, fpos_t *pos) {

	long ret;

	assert(stream);

	ret = ftell(stream);

	if(ret != -1) {
		*pos = ret;
		ret = 0;
	}

	return (int)ret;
}
