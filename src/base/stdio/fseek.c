
#define _ELIBC_SOURCE
#include "c/_support.h"
#include <assert.h>
#include <stdio.h>

/**
 * @brief Set the position indicator of a stream (thread-unsafe)
 *
 * @param stream the stream to set the position of
 * @param offset the offset to set the position to
 * @param whence the reference point for the offset
 * @return int 0 on success, or a negative value on error
 */
int __elibc_fseek(FILE *stream, long offset, int whence) {

	assert(stream);

	/* a seek is a synchronizing operation */
	if (__elibc_fflush(stream) != 0) {
		return -1;
	}

	/* just in case, reset the buffer pointers */
	_FDATA(stream)->buffer_first = _FDATA(stream)->buffer_start;
	_FDATA(stream)->buffer_last  = _FDATA(stream)->buffer_start;

	/* TODO(eteran): catch any errors at all */
	__elibc_sys_lseek(_ELIBC_FILENO(stream), offset, whence);

	__elibc_clearerr(stream);

	return 0;
}

/**
 * @brief Set the position indicator of a stream
 *
 * @param stream the stream to set the position of
 * @param offset the offset to set the position to
 * @param whence the reference point for the offset
 * @return int 0 on success, or a negative value on error
 */
int fseek(FILE *stream, long offset, int whence) {
	int r;
	__ELIBC_WITH_LOCK(__elibc_fseek(stream, offset, whence), &r);
	return r;
}
