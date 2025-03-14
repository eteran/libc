
#define _ELIBC_SOURCE
#include <stdarg.h>
#include <stdio.h>
#include <wchar.h>

/**
 * @brief Write formatted output to stdout
 *
 * @param format format string
 * @param ap variable argument list
 * @return int number of wide characters written, not including the
 * terminating null wide-character, or a negative value if an error
 * occurred.
 */
int vwprintf(const wchar_t *format, va_list ap) {
	return vfwprintf(stdout, format, ap);
}
