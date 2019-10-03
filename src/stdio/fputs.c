
#define __ELIBC_SOURCE
#include <stdio.h>
#include <assert.h>

/*------------------------------------------------------------------------------
// Name: __elibc_fputs
//----------------------------------------------------------------------------*/
static int __elibc_fputs(const char *_RESTRICT s, FILE *_RESTRICT stream) {

	assert(s);
	assert(stream);

	while(*s != '\0') {
		if(__elibc_fputc(*s++, stream, 0x02) == -1) {
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
	__elibc_lock_stream(stream);
	r = __elibc_fputs(s, stream);
	__elibc_unlock_stream(stream);
	return r;
}
