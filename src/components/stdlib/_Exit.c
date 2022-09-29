
#define _ELIBC_SOURCE
#include "c/_support.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/*------------------------------------------------------------------------------
// Name: _Exit
//----------------------------------------------------------------------------*/
void _Exit(int status) {
	/* close all open file descriptors
	 * this will flush all of the streams,
	 * and delete any temp files created with tmpfile
	 */

	/* TODO(eteran): lock the list */
	while (__elibc_root_file_struct) {
		fclose(__elibc_root_file_struct);
	}

	/* actually free the FILE structures we saved for reuse */
	/* TODO(eteran): lock the list */
	while (__elibc_free_file_struct) {
		FILE *ptr = __elibc_free_file_struct;
		__elibc_free_file_struct = ptr->next;
#if defined(_ELIBC_USE_THREADS)
		pthread_mutex_destroy(&ptr->mutex);
#endif
		free(ptr);
	}

	/* call exit system call */
	__elibc_sys_exit(status & 0xff);

	/* just in case */
	abort();
}
