
#define __ELIBC_SOURCE
#include <wchar.h>
#include <assert.h>

/*------------------------------------------------------------------------------
// Name: mbrlen
//----------------------------------------------------------------------------*/
size_t mbrlen(const char *__ELIBC_RESTRICT s, size_t n, mbstate_t *__ELIBC_RESTRICT ps) {

	static _Thread_local mbstate_t state;
	assert(s);
	return mbrtowc(0, s, n, ps ? ps : &state);
}
