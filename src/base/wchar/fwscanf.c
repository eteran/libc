
#define _ELIBC_SOURCE
#include <stdio.h>
#include <wchar.h>

/**
 * @brief Read formatted input from a wide-character stream
 *
 * @param stream the input stream to read from
 * @param format the format string that specifies how the input should be interpreted
 * @param ... variable arguments to be filled with the input data
 * @return int Returns the number of input items successfully matched and assigned,
 * or EOF if an error occurred or the end of the input stream was reached.
 */
int fwscanf(FILE *_RESTRICT stream, const wchar_t *format, ...) {
	_UNUSED(stream);
	_UNUSED(format);
	return -1;
}
