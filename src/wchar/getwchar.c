
#define __ELIBC_SOURCE
#include <stdio.h>
#include <wchar.h>

/*------------------------------------------------------------------------------
// Name: getwchar
//----------------------------------------------------------------------------*/
wint_t getwchar(void) {
	return fgetwc(stdin);
}
