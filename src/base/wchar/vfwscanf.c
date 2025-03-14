
#define _ELIBC_SOURCE
#include <wchar.h>

/**
 * @brief Read formatted input from a wide-character stream
 *
 * @param stream The input stream to read from
 * @param format The format string that specifies how the input should be interpreted
 * @param arg The variable argument list that will be filled with the input data
 * @return int Returns the number of input items successfully matched and assigned,
 * or EOF if an error occurred or the end of the input stream was reached.
 */
int vfwscanf(FILE *_RESTRICT stream, const wchar_t *_RESTRICT format, va_list arg) {
	_UNUSED(stream);
	_UNUSED(format);
	_UNUSED(arg);

	/* TODO(eteran): implement this */
	return -1;
}
