
#define __ELIBC_SOURCE
#include <stdio.h>
#include <wchar.h>

/*------------------------------------------------------------------------------
// Name: wctob
// Desc: we only support ASCII and UTF-8, so there is a direct mapping for
//       for values below 0x80
//----------------------------------------------------------------------------*/
int wctob(wint_t c) {
	return (unsigned int)c < 128u ? (int)c : EOF;
}
