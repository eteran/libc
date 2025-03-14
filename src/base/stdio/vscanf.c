
#define _ELIBC_SOURCE
#include <stdarg.h>
#include <stdio.h>

/**
 * @brief Read formatted input from stdin
 *
 * @param format a pointer to the format string
 * @param ap a pointer to the variable argument list
 * @return int
 */
int vscanf(const char *_RESTRICT format, va_list ap) {
	return vfscanf(stdin, format, ap);
}
