
#define _ELIBC_SOURCE
#include <stdarg.h>
#include <stdio.h>
#include <wchar.h>

/**
 * @brief Write formatted output to a wide-character string
 *
 * @param wcs pointer to the wide-character string
 * @param maxlen maximum number of wide-characters to be written
 * @param format format string
 * @param args variable argument list
 * @return number of wide-characters written, not including the
 * terminating null wide-character, or a negative value if an error
 * occurred.
 */
int vswprintf(wchar_t *wcs, size_t maxlen, const wchar_t *format, va_list args) {
	_UNUSED(wcs);
	_UNUSED(maxlen);
	_UNUSED(format);
	_UNUSED(args);

	/* TODO(eteran): implement this */
	return -1;
}
