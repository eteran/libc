
#define __ELIBC_SOURCE
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
	__elibc_sys_close(__ELIBC_FILENO(stream));

	/* if the file is marked to remove on close, do it */
	if (_FDATA(stream)->flags & __ELIBC_FILE_DEL_ON_CLOSE) {

		/* TODO(eteran): deleting it by the original open name
		 * is flawed. I believe the UNIX way is to
		 * actually delete the file immidiately after
		 * the open, and the OS will automatically
		 * clean it up when we close it */
		remove(_FDATA(stream)->filename);
	}

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

	free(_FDATA(stream)->internal_buffer_ptr);

	if (!(_FDATA(stream)->flags & __ELIBC_FILE_STATIC_ALLOC)) {
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
	__elibc_lock_stream(stream);
	r = __elibc_fclose(stream);
	__elibc_unlock_stream(stream);
	return r;
}
