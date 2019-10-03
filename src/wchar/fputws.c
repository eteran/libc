
#define __ELIBC_SOURCE
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
		if (__elibc_fputc(*ws++, stream, 0x03) == -1) {
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
	__elibc_lock_stream(stream);
	r = __elibc_fputws(ws, stream);
	__elibc_unlock_stream(stream);
	return r;
}
