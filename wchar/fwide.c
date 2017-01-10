
#define __ELIBC_SOURCE
#include <stdio.h>
#include <wchar.h>
#include <assert.h>

/*------------------------------------------------------------------------------
// Name: __elibc_fwide
//----------------------------------------------------------------------------*/
int __elibc_fwide(FILE *stream, int mode) {

	assert(stream);

	/* TODO(eteran): implement this */
	(void)stream;

	if(mode > 0) {
		return 0;
	} else if(mode < 0) {
		return 0;
	} else {
		return 0;
	}
}

/*------------------------------------------------------------------------------
// Name: fwide
//----------------------------------------------------------------------------*/
int fwide(FILE *stream, int mode) {
	int r;
	__elibc_lock_stream(stream);
	r = __elibc_fwide(stream, mode);
	__elibc_unlock_stream(stream);
	return r;
}
