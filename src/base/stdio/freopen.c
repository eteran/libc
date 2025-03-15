
#define _ELIBC_SOURCE
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Open a file and associate it with a stream (thread-unsafe)
 *
 * @param path the path to the file to open
 * @param mode the mode to open the file in
 * @param stream the stream to associate the file with
 * @return a pointer to the stream associated with the file, or NULL on error
 */
static FILE *__elibc_freopen(const char *path, const char *mode, FILE *stream) {

	/* open up the new file */
	FILE *const new_file = fopen(path, mode);

	if (new_file) {

		/* swap internal structures */
		struct __elibc_file *const temp_data = _FDATA(stream);
		_FDATA(stream)                       = _FDATA(new_file);
		_FDATA(new_file)                     = temp_data;

		/* close the old file, it is now located here */
		(void)__elibc_fclose(new_file);

		/* TODO(eteran): catch any errors fclose might cause */
	} else {
		return 0;
	}

	return stream;
}

/**
 * @brief Open a file and associate it with a stream
 *
 * @param path the path to the file to open
 * @param mode the mode to open the file in
 * @param stream the stream to associate the file with
 * @return a pointer to the stream associated with the file, or NULL on error
 */
FILE *freopen(const char *path, const char *mode, FILE *stream) {
	FILE *r;
	__ELIBC_WITH_LOCK(__elibc_freopen(path, mode, stream), &r);
	return r;
}
