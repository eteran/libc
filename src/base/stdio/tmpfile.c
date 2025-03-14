
#define _ELIBC_SOURCE
#include "c/_support.h"
#include <stdio.h>

/**
 * @brief Create a temporary file
 *
 * @return FILE* a pointer to the created file, or NULL on error
 */
FILE *tmpfile(void) {
	FILE *file = 0;
	char tmp_file[L_tmpnam];

	/* TODO(eteran): is this function supposed to be atomic if possible? */

	const char *const name = tmpnam(tmp_file);

	if (name) {
		file = fopen(name, "w+b");

		if (file) {
			int result = __elibc_sys_unlink(name);
			if (result != 0) {
				/* TODO(eteran): what is the best way to handle this? */
			}
		}
	}

	return file;
}
