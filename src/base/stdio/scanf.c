
#define _ELIBC_SOURCE
#include <stdarg.h>
#include <stdio.h>

/**
 * @brief Read formatted input from standard input
 *
 * @param format a pointer to the format string
 * @param ... a variable argument list containing pointers to the variables to store the input in
 * @return int the number of input items successfully matched and assigned
 */
int scanf(const char *_RESTRICT format, ...) {
	int ret;
	va_list ap;
	va_start(ap, format);
	ret = vscanf(format, ap);
	va_end(ap);
	return ret;
}
