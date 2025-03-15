
#define _ELIBC_SOURCE
#include <stdarg.h>
#include <stdio.h>
#include <wchar.h>

/**
 * @brief Writes formatted output to stdout.
 *
 * @param format The format string that specifies how the output should be formatted.
 * @param ... The variable arguments that will be formatted and written to the stream.
 * @return Returns the number of wide-characters written, or a negative value if an error occurs.
 */
int wprintf(const wchar_t *_RESTRICT format, ...) {
	int ret;
	va_list ap;
	va_start(ap, format);
	ret = vwprintf(format, ap);
	va_end(ap);
	return ret;
}
