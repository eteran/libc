
#define __ELIBC_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>

/*------------------------------------------------------------------------------
// Name: __elibc_setvbuf
//----------------------------------------------------------------------------*/
int __elibc_setvbuf(FILE *__ELIBC_RESTRICT stream, char *__ELIBC_RESTRICT buf, int mode, size_t size) {
	int ret = 0;

	assert(stream);

	/* we use the existence of a buffer to tell if any operations have been
	 * performed on this stream, strictly speaking we don't even need
	 * to check, but it would be nice if this failed for some situations...
	 * I don't think this will catch the scenario of open -> seek -> setvbuf
	 * though.
	 */

	/* ignore invalid modes entirely */
	if(mode != _IONBF && mode != _IOLBF && mode != _IOFBF) {
		errno = EINVAL;
		return -1;
	}


	/* if either buf or size are 0, the other should be too */
	if((!buf && size != 0) || (buf && size == 0)) {
		errno = EINVAL;
		return -1;
	}

	/* store the mode */
	_FDATA(stream)->buf_mod = mode;

	/* if they specified a buffer, use it, if they didn't the next read/write
	 * will cause an allocation of one of the default size
	 */
	if(buf) {
		_FDATA(stream)->buffer_ptr      = buf;
		_FDATA(stream)->buffer_first    = buf;
		_FDATA(stream)->buffer_last     = buf;
		_FDATA(stream)->buffer_capacity = size;
	}

	return ret;
}

/*------------------------------------------------------------------------------
// Name: setvbuf
//----------------------------------------------------------------------------*/
int setvbuf(FILE *__ELIBC_RESTRICT stream, char *__ELIBC_RESTRICT buf, int mode, size_t size) {
	int r;
	__elibc_lock_stream(stream);
	r = __elibc_setvbuf(stream, buf, mode, size);
	__elibc_unlock_stream(stream);
	return r;
}