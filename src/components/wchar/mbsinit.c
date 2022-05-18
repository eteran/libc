
#define _ELIBC_SOURCE
#include <wchar.h>

/*------------------------------------------------------------------------------
// Name: mbsinit
//----------------------------------------------------------------------------*/
int mbsinit(const mbstate_t *ps) {

	if (ps) {
		return ps->expected == 0 && ps->seen == 0;
	}

	return 1;
}
