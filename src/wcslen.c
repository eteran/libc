
#define __ELIBC_SOURCE
#include <wchar.h>
#include <assert.h>

/*------------------------------------------------------------------------------
// Name: wcslen
//----------------------------------------------------------------------------*/
size_t wcslen(const wchar_t *s) {
	const wchar_t *s_ptr = s;

	assert(s);

	while(*s != L'\0') {
		++s;
	}

	return s - s_ptr;
}
