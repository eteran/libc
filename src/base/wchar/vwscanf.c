
#define _ELIBC_SOURCE
#include <wchar.h>

/**
 * @brief Read formatted input from stdin
 *
 * @param format format string
 * @param ap variable argument list
 * @return number of input items successfully matched and assigned
 * or EOF if an error occurred or the end of the input stream was reached.
 */
int vwscanf(const wchar_t *_RESTRICT format, va_list ap) {
	_UNUSED(format);
	_UNUSED(ap);

	/* TODO(eteran): implement this */
	return -1;
}
