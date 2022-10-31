
#define _ELIBC_SOURCE
#include <wchar.h>

/*------------------------------------------------------------------------------
// Name:
//----------------------------------------------------------------------------*/
int swscanf(const wchar_t *_RESTRICT ws, const wchar_t *_RESTRICT format, ...) {
	_UNUSED(ws);
	_UNUSED(format);
	return -1;
}
