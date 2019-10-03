
#define __ELIBC_SOURCE
#include "c/_support.h"
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
	while (__elibc_root_file_struct) {
		fclose(__elibc_root_file_struct);
	}

	/* call exit system call */
	__elibc_sys_exit(status & 0xff);

	/* just in case */
	abort();
}
