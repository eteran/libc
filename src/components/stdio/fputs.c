
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdio.h>

/*------------------------------------------------------------------------------
// Name: __elibc_fputs
//----------------------------------------------------------------------------*/
static int __elibc_fputs(const char *_RESTRICT s, FILE *_RESTRICT stream) {

	assert(s);
	assert(stream);

	while (*s != '\0') {
		if (__elibc_fputc(*s++, stream, _ELIBC_FILE_NARROW) == EOF) {
			return EOF;
		}
	}

	return 0;
}

/*------------------------------------------------------------------------------
// Name: fputs
//----------------------------------------------------------------------------*/
int fputs(const char *_RESTRICT s, FILE *_RESTRICT stream) {
	int r;
	__ELIBC_WITH_LOCK(__elibc_fputs(s, stream), &r);
	return r;
}
