
#define _ELIBC_SOURCE
#include <stdlib.h>
#include <wchar.h>

/*------------------------------------------------------------------------------
// Name: wcsrtombs
//----------------------------------------------------------------------------*/
size_t wcsrtombs(char *dest, const wchar_t **src, size_t n, mbstate_t *ps) {

	const wchar_t *first = *src;
	const wchar_t *last = *src + n;
	size_t count = 0;

	if (dest) {
		while (1) {
			if ((size_t)(last - first) < MB_CUR_MAX) {
				break;
			} else {
				const size_t rc = wcrtomb(dest, *first, ps);
				if (rc == (size_t)-1) {
					*src = first;
					return (size_t)-1;
				}

				if (rc == 0) {
					break;
				}

				dest += rc;
				++first;
				++count;
			}
		}
	} else {
		while (1) {
			const size_t rc = wcrtomb(0, *first, ps);
			if (rc == (size_t)-1) {
				*src = first;
				return (size_t)-1;
			}

			if (rc == 0) {
				break;
			}

			++first;
			++count;
		}
	}

	*src = 0;
	return count;
}
