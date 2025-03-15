
#define _ELIBC_SOURCE
#include <assert.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Set the buffering mode of a stream (thread-unsafe)
 *
 * @param stream the stream to set the buffering mode for
 * @param buf a pointer to the buffer to use, or NULL to use the default buffer
 * @param mode the buffering mode to use, one of _IONBF, _IOLBF or _IOFBF
 * @param size the size of the buffer to use, or 0 to use the default size
 * @return 0 on success, or a negative value on error
 */
static int __elibc_setvbuf(FILE *_RESTRICT stream, char *_RESTRICT buf, int mode, size_t size) {
	int ret = 0;

	assert(stream);

	/* we use the existence of a buffer to tell if any operations have been
	 * performed on this stream, strictly speaking we don't even need
	 * to check, but it would be nice if this failed for some situations...
	 * I don't think this will catch the scenario of open -> seek -> setvbuf
	 * though.
	 */

	/* ignore invalid modes entirely */
	if (mode != _IONBF && mode != _IOLBF && mode != _IOFBF) {
		errno = EINVAL;
		return -1;
	}

	/* if either buf or size are 0, the other should be too */
	if ((!buf && (size != 0)) || (buf && (size == 0))) {
		errno = EINVAL;
		return -1;
	}

	/* store the mode */
	_FDATA(stream)->buf_mode = mode;

	/* if they specified a buffer, use it, if they didn't the next read/write
	 * will cause an allocation of one of the default size
	 */
	if (buf) {
		_FDATA(stream)->buffer_start = buf;
		_FDATA(stream)->buffer_first = buf;
		_FDATA(stream)->buffer_last  = buf;
		_FDATA(stream)->buffer_end   = buf + size;
	}

	return ret;
}

/**
 * @brief Set the buffering mode of a stream
 *
 * @param stream the stream to set the buffering mode for
 * @param buf a pointer to the buffer to use, or NULL to use the default buffer
 * @param mode the buffering mode to use, one of _IONBF, _IOLBF or _IOFBF
 * @param size the size of the buffer to use, or 0 to use the default size
 * @return 0 on success, or a negative value on error
 */
int setvbuf(FILE *_RESTRICT stream, char *_RESTRICT buf, int mode, size_t size) {
	int r;
	__ELIBC_WITH_LOCK(__elibc_setvbuf(stream, buf, mode, size), &r);
	return r;
}
