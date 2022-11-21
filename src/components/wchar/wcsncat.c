
#define _ELIBC_SOURCE
#include <assert.h>
#include <wchar.h>

/*------------------------------------------------------------------------------
// Name: wcsncat
//----------------------------------------------------------------------------*/
wchar_t *wcsncat(wchar_t *_RESTRICT dest, const wchar_t *_RESTRICT src, size_t n) {
	wchar_t *dest_ptr = dest;

	assert(dest);
	assert(src);

	if (n != 0) {
		/* find the end of the string... */
		while (*dest_ptr != L'\0') {
			++dest_ptr;
		}

		/* copy the new string to that location */
		while (n-- && *src != L'\0') {
			*dest_ptr++ = *src++;
		}

		*dest_ptr = L'\0';
	}

	/* return pointer to combined string */
	return dest;
}
