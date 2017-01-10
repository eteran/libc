
#define __ELIBC_SOURCE
#include <stdio.h>

/*------------------------------------------------------------------------------
// Name: remove
//----------------------------------------------------------------------------*/
int remove(const char *pathname) {

	/* TODO: can pathname be NULL? */

	(void)pathname;

	/*
	remove deletes a name from the filesystem.  It calls unlink for files, and
	rmdir for directories.

	If the removed name was the last link to a file and no processes have  the
	file open the file is deleted and the space it was using is made available
	for reuse.

	If the name was the last link to a file but any processes still  have  the
	file open the file will remain in existence until the last file descriptor
	referring to it is closed.

	If the name referred to a symbolic link the link is removed.

	If the name referred to a socket, fifo  or  device  the  name  for  it  is
	removed but processes which have the object open may continue to use it.
	*/

	#ifdef __KERNEL__
		/* TODO: panic here, it is clearly a kernel bug... */
	#else
		/* TODO: something along these lines

		if (unlink(filename)) {
			if (errno == EISDIR) {
				return rmdir(filename);
			}
			return -1;
		}
		return 0;
		*/

	#endif

	return 0;
}
