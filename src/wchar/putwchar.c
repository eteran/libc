
#define __ELIBC_SOURCE
#include <stdio.h>
#include <wchar.h>

/*------------------------------------------------------------------------------
// Name: putwchar
//----------------------------------------------------------------------------*/
wint_t putwchar(wchar_t wc) {
	return fputwc(wc, stdout);
}
