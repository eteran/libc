
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

/*------------------------------------------------------------------------------
// Name: mbstowcs
//----------------------------------------------------------------------------*/
size_t mbstowcs(wchar_t *dest, const char *src, size_t n) {

	static _Thread_local mbstate_t state;

	const char *first = src;
	const char *last = src + n;
	size_t count = 0;

	if (dest) {
		while (1) {
			const size_t rc = mbrtowc(dest, first, (size_t)(last - first), &state);
			if (rc == (size_t)-1 || rc == (size_t)-2) {
				return (size_t)-1;
			}

			if (rc == 0) {
				break;
			}

			first += rc;
			++dest;
			++count;
		}
	} else {
		while (1) {
			const size_t rc = mbrtowc(0, first, (size_t)(last - first), &state);
			if (rc == (size_t)-1 || rc == (size_t)-2) {
				return (size_t)-1;
			}

			if (rc == 0) {
				break;
			}

			first += rc;
			++count;
		}
	}

	return count;
}
