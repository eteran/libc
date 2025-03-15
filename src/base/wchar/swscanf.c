
#define _ELIBC_SOURCE
#include <wchar.h>

/**
 * @brief Read formatted input from a wide-character string
 *
 * @param ws the wide-character string to be read
 * @param format format string
 * @param ... variable arguments to be filled with the input data
 * @return number of input items successfully matched and assigned
 * or EOF if an error occurred or the end of the input stream was reached.
 */
int swscanf(const wchar_t *_RESTRICT ws, const wchar_t *_RESTRICT format, ...) {
	_UNUSED(ws);
	_UNUSED(format);

	/* TODO(eteran): implement this */
	return -1;
}
