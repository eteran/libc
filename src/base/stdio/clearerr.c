
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdio.h>

/**
 * @brief Clear the end-of-file and error indicators for a stream (thread-unsafe)
 *
 * @param stream the stream to clear the indicators for
 */
int __elibc_clearerr(FILE *stream) {
	assert(stream);
	_FDATA(stream)->eof = 0;
	_FDATA(stream)->err = 0;
	return 0;
}

/**
 * @brief Clear the end-of-file and error indicators for a stream
 *
 * @param stream the stream to clear the indicators for
 */
void clearerr(FILE *stream) {
	int r;
	__ELIBC_WITH_LOCK(__elibc_clearerr(stream), &r);
}
