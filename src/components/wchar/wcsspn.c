
#define _ELIBC_SOURCE
#include <assert.h>
#include <wchar.h>

/*------------------------------------------------------------------------------
// Name: wcsspn
//----------------------------------------------------------------------------*/
size_t wcsspn(const wchar_t *s, const wchar_t *accept) {
	const wchar_t *s_ptr = s;

	assert(s);
	assert(accept);

	while (*s_ptr != L'\0') {
		if (wcschr(accept, *s_ptr) == 0) {
			break;
		}

		++s_ptr;
	}

	return (size_t)(s_ptr - s);
}
