
#define __ELIBC_SOURCE
#include <wchar.h>
#include <assert.h>

/*------------------------------------------------------------------------------
// Name: wcsspn
//----------------------------------------------------------------------------*/
size_t wcsspn(const wchar_t *s, const wchar_t *accept) {
	const wchar_t *s_ptr = s;

	assert(s);
	assert(accept);

	while(*s_ptr != '\0') {
		if(wcschr(accept, *s_ptr) == 0) {
			break;
		}

		++s_ptr;
	}

	return s_ptr - s;
}
