
#define __ELIBC_SOURCE
#include <wchar.h>
#include <stdio.h>

/*------------------------------------------------------------------------------
// Name: fwscanf
//----------------------------------------------------------------------------*/
int fwscanf(FILE *__ELIBC_RESTRICT stream, const wchar_t *format, ...) {
	(void)stream;
	(void)format;
	return -1;
}
