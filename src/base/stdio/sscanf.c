
#define _ELIBC_SOURCE
#include <stdarg.h>
#include <stdio.h>

/**
 * @brief Read formatted input from a string
 *
 * @param str a pointer to the string to read from
 * @param format a pointer to the format string
 * @param ... a variable argument list containing pointers to the variables to store the input in
 * @return the number of input items successfully matched and assigned
 */
int sscanf(const char *_RESTRICT str, const char *_RESTRICT format, ...) {
	int ret;
	va_list ap;
	va_start(ap, format);
	ret = vsscanf(str, format, ap);
	va_end(ap);
	return ret;
}
