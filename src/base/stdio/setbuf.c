
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdio.h>

/**
 * @brief Set the buffer for a stream
 *
 * @param stream the stream to set the buffer for
 * @param buf a pointer to the buffer to use, or NULL to use the default buffer
 */
void setbuf(FILE *_RESTRICT stream, char *_RESTRICT buf) {
	assert(stream);
	setvbuf(stream, buf, buf ? _IOFBF : _IONBF, BUFSIZ);
}
