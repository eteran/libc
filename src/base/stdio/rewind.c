
#define _ELIBC_SOURCE
#include <stdio.h>

/**
 * @brief Reset the position indicator of a stream (thread-unsafe)
 *
 * @param stream the stream to reset
 */
static void __elibc_rewind(FILE *stream) {
	_LIBC_PRECOND(stream);
	__elibc_fseek(stream, 0L, SEEK_SET);
	__elibc_clearerr(stream);
}

/**
 * @brief Reset the position indicator of a stream
 *
 * @param stream the stream to reset
 */
void rewind(FILE *stream) {
	_DEFER_UNLOCK FILE *fp = __elibc_lock_stream(stream);
	__elibc_rewind(fp);
}
