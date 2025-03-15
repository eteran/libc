
#define _ELIBC_SOURCE
#include <stdarg.h>
#include <stdio.h>

/**
 * @brief Read formatted input from a stream
 *
 * @param stream the stream to read from
 * @param format a pointer to the format string
 * @param ap a pointer to the variable argument list
 * @return the number of input items successfully matched and assigned
 */
int vfscanf(FILE *_RESTRICT stream, const char *_RESTRICT format, va_list ap) {
	_UNUSED(stream);
	_UNUSED(format);
	_UNUSED(ap);

	// TODO(eteran): implement this
	return -1;
}
