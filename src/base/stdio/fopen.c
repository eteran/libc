
#define _ELIBC_SOURCE
#include "c/_support.h"
#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define O_RDONLY 00
#define O_WRONLY 01
#define O_RDWR   02
#define O_CREAT  0100  /* not fcntl */
#define O_TRUNC  01000 /* not fcntl */
#define O_APPEND 02000

/**
 * @brief Open a file and associate it with a stream
 *
 * @param path the path to the file to open
 * @param mode the mode to open the file in
 * @return a pointer to the stream associated with the file, or NULL on error
 */
FILE *fopen(const char *path, const char *mode) {

	assert(path);
	assert(mode);

	{
		int fd         = -1;
		int mode_flags = 0;

		FILE *f = __elibc_allocate_file();
		if (!f) {
			return 0;
		}

		_FDATA(f) = malloc(sizeof(struct __elibc_file));
		if (!_FDATA(f)) {
			__elibc_free_file(f);
			return 0;
		}

		/* get the basic mode */
		switch (*mode) {
		case 'r':
			mode_flags = O_RDONLY;
			break;
		case 'w':
			mode_flags = (O_WRONLY | O_CREAT | O_TRUNC);
			break;
		case 'a':
			mode_flags = (O_WRONLY | O_CREAT | O_APPEND);
			break;
		default:
			free(_FDATA(f));
			__elibc_free_file(f);
			/* TODO; what's the correct error code */
			return 0;
		}

		/* TODO(eteran): handle the new C11 mode strings */

		++mode;

		/* ignore binary mode flag */
		if (*mode == 'b') {
			++mode;
		}

		/* modifier */
		if (*mode == '+') {
			++mode;
			mode_flags &= ~(O_RDONLY | O_WRONLY);
			mode_flags |= O_RDWR;
		}

		/* ignore the rest, we can add expansion flags here */
		while (*mode != '\0' && *mode != 'b') {
			++mode;
		}

		/* ignore binary mode flag, again, it's allowed to be the last char too */
		if (*mode == 'b') {
			++mode;
		}

		if (*mode != '\0') {
			free(_FDATA(f));
			__elibc_free_file(f);
			/* TODO(eteran): invalid mode string? */
			errno = EINVAL;
			return 0;
		}

		if ((fd = __elibc_sys_open(path, mode_flags)) == -1) {
			free(_FDATA(f));
			__elibc_free_file(f);
			/* TODO; what's the correct error code */
			return 0;
		}

		_FDATA(f)->fd               = fd;
		_FDATA(f)->buf_mode         = _IOFBF;
		_FDATA(f)->err              = 0;
		_FDATA(f)->eof              = 0;
		_FDATA(f)->orientation_set  = 0;
		_FDATA(f)->orientation_wide = _ELIBC_FILE_NARROW;
		_FDATA(f)->static_alloc     = 0;
		_FDATA(f)->free_buffer      = 0;
		_FDATA(f)->buffer_start     = 0;
		_FDATA(f)->buffer_end       = 0;
		_FDATA(f)->buffer_first     = 0;
		_FDATA(f)->buffer_last      = 0;

		/* TODO(eteran): lock the list */

		/* insert at the beginning of the list */
		f->next = __elibc_root_file_struct;
		f->prev = NULL;

		__elibc_root_file_struct->prev = f;
		__elibc_root_file_struct       = f;

#if defined(_ELIBC_USE_THREADS)
		pthread_mutex_init(&f->mutex, NULL);
#endif
		return f;
	}
}
