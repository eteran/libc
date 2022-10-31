
#define _ELIBC_SOURCE
#include <stdarg.h>
#include <stdio.h>

/* TODO(eteran): implement */
int vfscanf(FILE *_RESTRICT stream, const char *_RESTRICT format, va_list ap) {
	_UNUSED(stream);
	_UNUSED(format);
	_UNUSED(ap);
	return -1;
}
