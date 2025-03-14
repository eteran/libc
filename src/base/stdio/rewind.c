
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdio.h>

/**
 * @brief Reset the position indicator of a stream (thread-unsafe)
 *
 * @param stream the stream to reset
 * @return int 0 on success, or a negative value on error
 */
static int __elibc_rewind(FILE *stream) {
	assert(stream);
	__elibc_fseek(stream, 0L, SEEK_SET);
	__elibc_clearerr(stream);
	return 0;
}

/**
 * @brief Reset the position indicator of a stream
 *
 * @param stream the stream to reset
 */
void rewind(FILE *stream) {
	int r;
	__ELIBC_WITH_LOCK(__elibc_rewind(stream), &r);
	(void)r;
}
