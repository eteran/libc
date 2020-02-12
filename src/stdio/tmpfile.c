
#define __ELIBC_SOURCE
#include <stdio.h>

/*------------------------------------------------------------------------------
// Name: tmpfile
//----------------------------------------------------------------------------*/
FILE *tmpfile(void) {
	FILE *file = 0;
	char tmp_file[L_tmpnam];

	/* TODO(eteran): is this function supposed to be atomic if possible? */

	const char *const name = tmpnam(tmp_file);

	if (name) {
		file = fopen(name, "w+b");

		if (file) {
			/* set the file to autodelete on close */
			_FDATA(file)->flags |= __ELIBC_FILE_DEL_ON_CLOSE;
		}
	}

	return file;
}
