
#define __ELIBC_SOURCE
#include <stdio.h>
#include <wchar.h>

/*------------------------------------------------------------------------------
// Name: btowc
// Desc: we only support ASCII and UTF-8, so in both cases, a value less than
//       0x80 maps directly
//----------------------------------------------------------------------------*/
wint_t btowc(int c) {
	return (wint_t)c < 128u ? (wint_t)c : WEOF;
}
