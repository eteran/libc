
#define _ELIBC_SOURCE
#include <assert.h>
#include <wchar.h>

/*------------------------------------------------------------------------------
// Name: wcslen
//----------------------------------------------------------------------------*/
size_t wcslen(const wchar_t *s) {
	const wchar_t *s_ptr = s;

	assert(s);

	while (*s != L'\0') {
		++s;
	}

	return (size_t)(s - s_ptr);
}
