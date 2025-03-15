
#define _ELIBC_SOURCE
#include <stdarg.h>
#include <stdio.h>

/**
 * @brief Write formatted output to a string
 *
 * @param str a pointer to the destination string
 * @param format a pointer to the format string
 * @param ... a variable argument list containing the values to format
 * @return the number of characters written to the string, or a negative value on error
 */
int sprintf(char *_RESTRICT str, const char *_RESTRICT format, ...) {
	int ret;
	va_list ap;
	va_start(ap, format);
	ret = vsprintf(str, format, ap);
	va_end(ap);
	return ret;
}
