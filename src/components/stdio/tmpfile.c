
#define _ELIBC_SOURCE
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
			/* set the file to auto-delete on close */
			_FDATA(file)->flags |= _ELIBC_FILE_AUTO_CLOSE;
		}
	}

	return file;
}
