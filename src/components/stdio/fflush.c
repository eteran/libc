
#define _ELIBC_SOURCE
#include "c/_support.h"
#include <stdio.h>

/*------------------------------------------------------------------------------
// Name: __elibc_fflush_all
//----------------------------------------------------------------------------*/
int __elibc_fflush_all() {
	/* flush all open output streams */
	FILE *p = __elibc_root_file_struct;
	while (p) {
		if (__elibc_fflush(p) != 0) {
			return EOF;
		}
		p = p->next;
	}
	return 0;
}

/*------------------------------------------------------------------------------
// Name: __elibc_fflush_stream
//----------------------------------------------------------------------------*/
int __elibc_fflush_stream(FILE *stream) {

	struct __elibc_file *const impl = _FDATA(stream);
	const int fd = _ELIBC_FILENO(stream);

	if (fd != -1) {
		if (impl->buffer_first != impl->buffer_ptr) {

			/* if p2 == ptr then the last operation was a write */
			if (impl->buffer_last == impl->buffer_ptr) {
				const size_t n = impl->buffer_first - impl->buffer_ptr;

				const ssize_t r = __elibc_sys_write(fd, impl->buffer_ptr, n);

				if (r < 0) {
					/* TODO(eteran): set errno */
					return EOF;
				}
			}
		}
	}

	impl->buffer_first = impl->buffer_ptr;
	impl->buffer_last = impl->buffer_ptr;
	return 0;
}

/*------------------------------------------------------------------------------
// Name: __elibc_fflush
//----------------------------------------------------------------------------*/
int __elibc_fflush(FILE *stream) {
	if (stream) {
		return __elibc_fflush_stream(stream);
	} else {
		return __elibc_fflush_all();
	}
}

/*------------------------------------------------------------------------------
// Name: fflush
//----------------------------------------------------------------------------*/
int fflush(FILE *stream) {
	int r;
	__elibc_lock_stream(stream);
	r = __elibc_fflush(stream);
	__elibc_unlock_stream(stream);
	return r;
}
