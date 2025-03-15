
#define _ELIBC_SOURCE
#include <stdarg.h>
#include <stdio.h>

/**
 * @brief Write formatted output to standard output
 *
 * @param format a pointer to the format string
 * @param ... a variable argument list containing the values to format
 * @return the number of characters written to the output, or a negative value on error
 */
int printf(const char *_RESTRICT format, ...) {
	int ret;
	va_list ap;
	va_start(ap, format);
	ret = vprintf(format, ap);
	va_end(ap);
	return ret;
}
