
#define _ELIBC_SOURCE
#include <assert.h>
#include <wchar.h>

/*------------------------------------------------------------------------------
// Name: wcsncmp
//----------------------------------------------------------------------------*/
int wcsncmp(const wchar_t *s1, const wchar_t *s2, size_t n) {
	int ret = 0;

	assert(s1);
	assert(s2);

	while (!ret && (*s1 || *s2) && n--) {
		ret = (*s1++ - *s2++);
	}

	return ret;
}
