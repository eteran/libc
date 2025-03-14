
#define _ELIBC_SOURCE
#include "c/_support.h"
#include <assert.h>
#include <stdio.h>

/**
 * @brief Flush a stream (thread-unsafe)
 *
 * @param stream the stream to flush
 * @return int 0 on success, or EOF on error
 */
int __elibc_fflush(FILE *stream) {

	assert(stream);
	struct __elibc_file *const impl = _FDATA(stream);
	const int fd                    = _ELIBC_FILENO(stream);

	if (fd != -1) {
		if (impl->buffer_first != impl->buffer_start) {

			/* if p2 == ptr then the last operation was a write */
			if (impl->buffer_last == impl->buffer_start) {
				const size_t n  = (size_t)(impl->buffer_first - impl->buffer_start);
				const ssize_t r = __elibc_sys_write(fd, impl->buffer_start, n);

				if (r < 0) {
					/* TODO(eteran): set errno */
					return EOF;
				}
			}
		}
	}

	impl->buffer_first = impl->buffer_start;
	impl->buffer_last  = impl->buffer_start;
	return 0;
}

/**
 * @brief Flush a stream
 *
 * @param stream the stream to flush, or NULL to flush all streams
 * @return int 0 on success, or EOF on error
 */
int fflush(FILE *stream) {

	if (stream) {
		int r;
		__ELIBC_WITH_LOCK(__elibc_fflush(stream), &r);
		return r;
	} else {
		/* flush all open output streams */
		FILE *p;

		/* TODO(eteran): lock the list */
		for (p = __elibc_root_file_struct; p; p = p->next) {
			int r;
			__ELIBC_WITH_LOCK(__elibc_fflush(p), &r);
			if (r != 0) {
				return r;
			}
		}
		return 0;
	}
}
