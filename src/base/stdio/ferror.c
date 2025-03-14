
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdio.h>

/**
 * @brief Check if a stream has encountered an error (thread-unsafe)
 *
 * @param stream the stream to check
 * @return int non-zero if the stream has encountered an error, zero otherwise
 */
static int __elibc_ferror(FILE *stream) {
	assert(stream);
	return _FDATA(stream)->err != 0;
}

/**
 * @brief Check if a stream has encountered an error
 *
 * @param stream the stream to check
 * @return int non-zero if the stream has encountered an error, zero otherwise
 */
int ferror(FILE *stream) {
	int r;
	__ELIBC_WITH_LOCK(__elibc_ferror(stream), &r);
	return r;
}
