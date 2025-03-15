
#define _ELIBC_SOURCE
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>

/**
 * @brief Write formatted output to a stream
 *
 * @param stream the stream to write to
 * @param format a pointer to the format string
 * @param ... a variable argument list containing the values to format
 * @return the number of characters written, or a negative value on error
 */
int fprintf(FILE *_RESTRICT stream, const char *_RESTRICT format, ...) {
	int ret;
	va_list ap;
	va_start(ap, format);
	ret = vfprintf(stream, format, ap);
	va_end(ap);
	return ret;
}
