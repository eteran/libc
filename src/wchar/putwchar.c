
#define __ELIBC_SOURCE
#include <wchar.h>
#include <stdio.h>

/*------------------------------------------------------------------------------
// Name: putwchar
//----------------------------------------------------------------------------*/
wint_t putwchar(wchar_t wc) {
	return fputwc(wc, stdout);
}
