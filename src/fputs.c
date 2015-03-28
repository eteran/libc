
#define __ELIBC_SOURCE
#include <stdio.h>
#include <assert.h>

/*------------------------------------------------------------------------------
// Name: __elibc_fputs
//----------------------------------------------------------------------------*/
int __elibc_fputs(const char *__ELIBC_RESTRICT s, FILE *__ELIBC_RESTRICT stream) {

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
int fputs(const char *__ELIBC_RESTRICT s, FILE *__ELIBC_RESTRICT stream) {

	int r;
	__elibc_lock_stream(stream);
	r = __elibc_fputs(s, stream);
	__elibc_unlock_stream(stream);
	return r;
}
