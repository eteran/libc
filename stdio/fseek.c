
#define __ELIBC_SOURCE
#include <stdio.h>
#include <assert.h>
#include "c/_support.h"

/*------------------------------------------------------------------------------
// Name: __elibc_fseek
//----------------------------------------------------------------------------*/
int __elibc_fseek(FILE *stream, long offset, int whence) {

	assert(stream);

	/* a seek is a syncronizing operation */
	if(__elibc_fflush(stream) != 0) {
		return -1;
	}

	/* just in case, reset the buffer pointers */
	_FDATA(stream)->buffer_first = _FDATA(stream)->buffer_ptr;
	_FDATA(stream)->buffer_last  = _FDATA(stream)->buffer_ptr;

	/* TODO(eteran): catch any errors at all */
	__elibc_sys_lseek(__ELIBC_FILENO(stream), offset, whence);

	__elibc_clearerr(stream);

	return 0;
}

/*------------------------------------------------------------------------------
// Name: fseek
//----------------------------------------------------------------------------*/
int fseek(FILE *stream, long offset, int whence) {

	int r;
	__elibc_lock_stream(stream);
	r = __elibc_fseek(stream, offset, whence);
	__elibc_unlock_stream(stream);
	return r;
}
