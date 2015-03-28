
#define __ELIBC_SOURCE
#include <wchar.h>
#include <assert.h>

/*------------------------------------------------------------------------------
// Name: wmemcmp
//----------------------------------------------------------------------------*/
int wmemcmp(const wchar_t *s1, const wchar_t *s2, size_t n) {
	int ret = 0;
	const wchar_t *s1_ptr = s1;
	const wchar_t *s2_ptr = s2;

	assert(s1);
	assert(s2);

	while(!ret && n--) {
		ret = (*s2_ptr++ - *s1_ptr++);
	}

	return ret;
}
