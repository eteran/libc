
#define _ELIBC_SOURCE
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

/*------------------------------------------------------------------------------
// Name: mblen
//----------------------------------------------------------------------------*/
int mblen(const char *s, size_t n) {
	static _Thread_local mbstate_t state;

	if (!s) {
		memset(&state, 0, sizeof(state));
		return 0;
	}
	return (int)mbrtowc(0, s, n, &state);
}
