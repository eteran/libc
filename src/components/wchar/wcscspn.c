
#define _ELIBC_SOURCE
#include <assert.h>
#include <wchar.h>

/*------------------------------------------------------------------------------
// Name: wcscspn
//----------------------------------------------------------------------------*/
size_t wcscspn(const wchar_t *s, const wchar_t *reject) {
	const wchar_t *s_ptr = s;

	assert(s);
	assert(reject);

	while (*s_ptr != '\0') {
		if (wcschr(reject, *s_ptr) != 0) {
			break;
		}

		++s_ptr;
	}

	return (size_t)(s_ptr - s);
}
