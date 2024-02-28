
#define _ELIBC_SOURCE
#include <stdio.h>
#include <wchar.h>

/*------------------------------------------------------------------------------
// Name: fwscanf
//----------------------------------------------------------------------------*/
int fwscanf(FILE *_RESTRICT stream, const wchar_t *format, ...) {
	_UNUSED(stream);
	_UNUSED(format);
	return -1;
}
