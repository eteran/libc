
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdio.h>

/**
 * @brief Reset the position indicator of a stream (thread-unsafe)
 *
 * @param stream the stream to reset
 * @return 0 on success, or a negative value on error
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
	_DEFER_UNLOCK FILE *fp = __elibc_lock_stream(stream);
	(void)__elibc_rewind(fp);
}
