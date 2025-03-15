
#define _ELIBC_SOURCE
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <wchar.h>

/**
 * @brief Write formatted output to a wide-character stream
 *
 * @param stream the output stream to write to
 * @param format the format string that specifies how the output should be formatted
 * @param ... variable arguments to be formatted and written to the stream
 * @return number of wide-characters written, not including the
 * terminating null wide-character, or a negative value if an error
 * occurred.
 */
int fwprintf(FILE *_RESTRICT stream, const wchar_t *_RESTRICT format, ...) {
	int ret;
	va_list ap;
	va_start(ap, format);
	ret = vfwprintf(stream, format, ap);
	va_end(ap);
	return ret;
}
