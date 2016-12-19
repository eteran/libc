
#define __ELIBC_SOURCE
#include <wchar.h>
#include <assert.h>

/*------------------------------------------------------------------------------
// Name: wcscspn
//----------------------------------------------------------------------------*/
size_t wcscspn(const wchar_t *s, const wchar_t *reject) {
	const wchar_t *s_ptr = s;

	assert(s);
	assert(reject);

	while(*s_ptr != '\0') {
		if(wcschr(reject, *s_ptr) != 0) {
			break;
		}

		++s_ptr;
	}

	return s_ptr - s;
}
