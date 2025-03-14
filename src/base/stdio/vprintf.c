
#define _ELIBC_SOURCE
#include <stdarg.h>
#include <stdio.h>

/**
 * @brief Write formatted output to stdout
 *
 * @param format a pointer to the format string
 * @param ap a pointer to the variable argument list
 * @return int the number of characters written to the string, or a negative value on error
 */
int vprintf(const char *_RESTRICT format, va_list ap) {
	return vfprintf(stdout, format, ap);
}
