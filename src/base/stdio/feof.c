
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdio.h>

/**
 * @brief Check if the end-of-file indicator for a stream is set (thread-unsafe)
 *
 * @param stream the stream to check
 * @return non-zero if the end-of-file indicator is set, zero otherwise
 */
static int __elibc_feof(FILE *stream) {
	assert(stream);
	return _FDATA(stream)->eof != 0;
}

/**
 * @brief Check if the end-of-file indicator for a stream is set
 *
 * @param stream the stream to check
 * @return non-zero if the end-of-file indicator is set, zero otherwise
 */
int feof(FILE *stream) {
	int r;
	__ELIBC_WITH_LOCK(__elibc_feof(stream), &r);
	return r;
}
