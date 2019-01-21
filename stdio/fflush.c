
#define __ELIBC_SOURCE
#include <stdio.h>
#include "c/_support.h"

/*------------------------------------------------------------------------------
// Name: __elibc_fflush
//----------------------------------------------------------------------------*/
int __elibc_fflush(FILE *stream) {

	if(stream) {
		if(__ELIBC_FILENO(stream) != -1) {
			if(_FDATA(stream)->buffer_first != _FDATA(stream)->buffer_ptr) {

				/* if p2 == ptr then the last operation was a write */
				if(_FDATA(stream)->buffer_last == _FDATA(stream)->buffer_ptr) {
					const size_t n = _FDATA(stream)->buffer_first - _FDATA(stream)->buffer_ptr;

					const ssize_t r = __elibc_sys_write(
						__ELIBC_FILENO(stream),
						_FDATA(stream)->buffer_ptr,
						n);

					if(r < 0) {
						/* TODO: set errno */
						return EOF;
					}
				}
			}
		}

		_FDATA(stream)->buffer_first = _FDATA(stream)->buffer_ptr;
		_FDATA(stream)->buffer_last  = _FDATA(stream)->buffer_ptr;
		return 0;
	} else {
		/* flush all open output streams */
		FILE *p = __elibc_root_file_struct;
		while(p) {
			if(__elibc_fflush(p) != 0) {
				return EOF;
			}
			p = p->next;
		}
		return 0;
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
