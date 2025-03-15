
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdarg.h>
#include <stdio.h>

/**
 * @brief Read formatted input from a stream
 *
 * @param stream the stream to read from
 * @param format a pointer to the format string
 * @param ... a variable argument list containing pointers to the variables to store the input in
 * @return the number of input items successfully matched and assigned
 */
int fscanf(FILE *_RESTRICT stream, const char *_RESTRICT format, ...) {
	int ret;
	va_list ap;

	assert(stream);
	assert(format);

	va_start(ap, format);
	ret = vfscanf(stream, format, ap);
	va_end(ap);
	return ret;
}
