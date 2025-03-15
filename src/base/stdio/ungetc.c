
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdio.h>

/**
 * @brief Push a character back to the input stream (thread-unsafe)
 *
 * @param c the character to push back
 * @param stream the input stream to push the character back to
 * @return the character pushed back, or EOF on error
 */
static int __elibc_ungetc(int c, FILE *stream) {

	assert(stream);

	assert(_FDATA(stream)->orientation_set == 0 || _FDATA(stream)->orientation_wide == 0);

	_FDATA(stream)->orientation_set  = 1;
	_FDATA(stream)->orientation_wide = _ELIBC_FILE_NARROW;

	if (_FDATA(stream)->buffer_first == _FDATA(stream)->buffer_start) {
		return EOF;
	}

	if (c == EOF) {
		return EOF;
	}

	*--_FDATA(stream)->buffer_first = (char)c;
	return c;
}

/**
 * @brief Push a character back to the input stream
 *
 * @param c the character to push back
 * @param stream the input stream to push the character back to
 * @return the character pushed back, or EOF on error
 */
int ungetc(int c, FILE *stream) {
	int r;
	__ELIBC_WITH_LOCK(__elibc_ungetc(c, stream), &r);
	return r;
}
