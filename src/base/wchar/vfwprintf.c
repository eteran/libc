
#define _ELIBC_SOURCE
#include <stdarg.h>
#include <stdio.h>
#include <wchar.h>

/* TODO(eteran): implement this */

/**
 * @brief Write formatted output to a stream
 *
 * @param stream The stream to write to
 * @param format The format string that specifies how the output should be formatted
 * @param args The variable argument list that will be formatted and written to the stream
 * @return Returns the number of wide-characters written, not including the
 * terminating null wide-character, or a negative value if an error occurs.
 */
int vfwprintf(FILE *stream, const wchar_t *format, va_list args) {
	_UNUSED(stream);
	_UNUSED(format);
	_UNUSED(args);

	/* TODO(eteran): implement this */
	return -1;
}
