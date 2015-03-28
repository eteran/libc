
#define __ELIBC_SOURCE
#include <wchar.h>
#include <assert.h>

/*------------------------------------------------------------------------------
// Name: wcsncat
// TODO: double check this for correctness
//----------------------------------------------------------------------------*/
wchar_t *wcsncat(wchar_t *__ELIBC_RESTRICT dest, const wchar_t *__ELIBC_RESTRICT src, size_t n) {
	wchar_t *dest_ptr = dest;

	assert(dest);
	assert(src);

	if(n != 0) {
		/* find the end of the string... */
		while(*dest_ptr != '\0') {
			++dest_ptr;
		}

		/* copy the new string to that location */
		while(n-- && *src != '\0') {
			*dest_ptr++ = *src++;
		}

		*dest_ptr = '\0';
	}

	/* return pointer to combined string */
	return dest;
}
