
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdio.h>
#include <wchar.h>

/*------------------------------------------------------------------------------
// Name: __elibc_fputws
//----------------------------------------------------------------------------*/
static int __elibc_fputws(const wchar_t *ws, FILE *stream) {

	assert(ws);
	assert(stream);

	while (*ws != '\0') {
		if (__elibc_fputc(*ws++, stream, _ELIBC_FILE_WIDE) == EOF) {
			return EOF;
		}
	}

	return 0;
}

/*------------------------------------------------------------------------------
// Name: fputws
//----------------------------------------------------------------------------*/
int fputws(const wchar_t *ws, FILE *stream) {
	int r;
	__ELIBC_WITH_LOCK(__elibc_fputws(ws, stream), &r);
	return r;
}
