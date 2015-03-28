
#define __ELIBC_SOURCE
#include <wchar.h>
#include <stdio.h>

/*------------------------------------------------------------------------------
// Name: getwchar
//----------------------------------------------------------------------------*/
wint_t getwchar(void) {
	return fgetwc(stdin);
}
