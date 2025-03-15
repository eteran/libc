
#define _ELIBC_SOURCE
#include <stdarg.h>
#include <stdio.h>
#include <wchar.h>

/**
 * @brief Reads formatted input from stdin.
 *
 * @param format The format string that specifies how the input should be interpreted.
 * @param ... The variable arguments that will be filled with the input data.
 * @return Returns the number of input items successfully matched and assigned, or EOF if an error occurs.
 */
int wscanf(const wchar_t *_RESTRICT format, ...) {
	int ret;
	va_list ap;
	va_start(ap, format);
	ret = vwscanf(format, ap);
	va_end(ap);
	return ret;
}
