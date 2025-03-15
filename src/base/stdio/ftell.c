
#define _ELIBC_SOURCE
#include "c/_support.h"
#include <assert.h>
#include <stdio.h>

/**
 * @brief Get the current position of the file pointer in a stream
 *
 * @param stream the stream to get the position of
 * @return the current position of the file pointer, or -1 on error
 */
long ftell(FILE *stream) {

	assert(stream);
	return (long)__elibc_sys_lseek(_ELIBC_FILENO(stream), 0, SEEK_CUR);
}
