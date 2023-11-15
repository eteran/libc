
#define _ELIBC_SOURCE
#include "c/_support.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/*------------------------------------------------------------------------------
// Name: __elibc_fclose
//----------------------------------------------------------------------------*/
int __elibc_fclose(FILE *stream) {

	assert(stream);

	if (__elibc_fflush(stream) != 0) {
		return EOF;
	}

	/* TODO(eteran): deal with any errors __elibc_sys_close might return */
	__elibc_sys_close(_ELIBC_FILENO(stream));

	/* TODO(eteran): lock the list */
	do {
		/* unlink this FILE from the linked list */
		FILE *const prev = stream->prev;
		FILE *const next = stream->next;

		if (prev) {
			prev->next = next;
		}

		if (next) {
			next->prev = prev;
		}

		if (__elibc_root_file_struct == stream) {
			__elibc_root_file_struct = next;
		}
	} while (0);

	if (_FDATA(stream)->free_buffer) {
		free(_FDATA(stream)->buffer_start);
	}

	if (!(_FDATA(stream)->static_alloc)) {
		free(_FDATA(stream));
	}

	if (stream != __elibc_stdin && stream != __elibc_stdout && stream != __elibc_stderr) {
		__elibc_free_file(stream);
	}

	return 0;
}

/*------------------------------------------------------------------------------
// Name: fclose
//----------------------------------------------------------------------------*/
int fclose(FILE *stream) {
	int r;
	__ELIBC_WITH_LOCK(__elibc_fclose(stream));
	return r;
}
