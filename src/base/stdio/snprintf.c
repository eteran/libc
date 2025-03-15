
#define _ELIBC_SOURCE
#include <stdarg.h>
#include <stdio.h>

/**
 * @brief Write formatted output to a string
 *
 * @param str a pointer to the destination string
 * @param size the maximum number of bytes to write to the destination string
 * @param format a pointer to the format string
 * @param ... a variable argument list containing the values to format
 * @return the number of characters written to the string, or a negative value on error
 */
int snprintf(char *str, size_t size, const char *format, ...) {
	int ret;
	va_list ap;
	va_start(ap, format);
	ret = vsnprintf(str, size, format, ap);
	va_end(ap);
	return ret;
}
