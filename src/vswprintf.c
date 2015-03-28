
#define __ELIBC_SOURCE
#include <stdarg.h>
#include <stdio.h>
#include <wchar.h>

int vswprintf(wchar_t *wcs, size_t n, const wchar_t *format, va_list ap) {
	(void)wcs;
	(void)n;
	(void)format;
	(void)ap;
	/* TODO: implement this */
	return -1;
}
