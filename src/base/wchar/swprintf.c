
#define _ELIBC_SOURCE
#include <stdarg.h>
#include <stdio.h>
#include <wchar.h>

/**
 * @brief Write formatted output to a wide-character string
 *
 * @param str pointer to the wide-character string
 * @param n maximum number of wide-characters to be written
 * @param format format string
 * @param ...  variable arguments to be formatted and written to the stream
 * @return number of wide-characters written, not including the
 * terminating null wide-character, or a negative value if an error
 * occurred.
 */
int swprintf(wchar_t *_RESTRICT str, size_t n, const wchar_t *_RESTRICT format, ...) {
	int ret;
	va_list ap;
	va_start(ap, format);
	ret = vswprintf(str, n, format, ap);
	va_end(ap);
	return ret;
}
