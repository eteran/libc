
#define __ELIBC_SOURCE
#include <wchar.h>

/*------------------------------------------------------------------------------
// Name: wcwidth
//----------------------------------------------------------------------------*/
int wcwidth(wchar_t wc) {

	if (wc == L'\0') {
		return 0;
	}

	/* TODO(eteran): implement! */
	return 1;
}
