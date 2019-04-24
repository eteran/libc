
#define __ELIBC_SOURCE
#include <stdarg.h>
#include <stdio.h>

/* TODO(eteran): implement */
int vfscanf(FILE *__ELIBC_RESTRICT stream, const char *__ELIBC_RESTRICT format, va_list ap) {
	(void)stream;
	(void)format;
	(void)ap;
	return -1;
}
