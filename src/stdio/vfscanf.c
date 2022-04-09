
#define _ELIBC_SOURCE
#include <stdarg.h>
#include <stdio.h>

/* TODO(eteran): implement */
int vfscanf(FILE *_RESTRICT stream, const char *_RESTRICT format, va_list ap) {
	(void)stream;
	(void)format;
	(void)ap;
	return -1;
}
