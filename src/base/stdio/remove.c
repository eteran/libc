
#define _ELIBC_SOURCE
#include <stdio.h>

/**
 * @brief Remove a file or directory
 *
 * @param pathname the path to the file or directory to remove
 * @return 0 on success, or a negative value on error
 */
int remove(const char *pathname) {

	/* TODO(eteran): can pathname be NULL? */

	_UNUSED(pathname);

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

	/* TODO(eteran): something along these lines

			if (unlink(filename)) {
					if (errno == EISDIR) {
							return rmdir(filename);
					}
					return -1;
			}
			return 0;
	*/

	return 0;
}
