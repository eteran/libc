
#define _ELIBC_SOURCE
#include <assert.h>
#include <wchar.h>

/*------------------------------------------------------------------------------
// Name: mbrlen
//----------------------------------------------------------------------------*/
size_t mbrlen(const char *_RESTRICT s, size_t n, mbstate_t *_RESTRICT ps) {

	static _Thread_local mbstate_t state;
	assert(s);
	return mbrtowc(0, s, n, ps ? ps : &state);
}
