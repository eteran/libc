
#define _ELIBC_SOURCE
#include <assert.h>
#include <wchar.h>

/**
 * @brief Copies n wide characters from the source string to the destination string, handling overlapping memory regions.
 *
 * @param dest The destination string where the wide characters will be copied to.
 * @param src The source string from which the wide characters will be copied.
 * @param n The number of wide characters to copy.
 * @return wchar_t*
 */
wchar_t *wmemmove(wchar_t *dest, const wchar_t *src, size_t n) {

	assert(dest);
	assert(src);

	if (dest > src) {
		/* copy backwards */
		wchar_t *dest_ptr      = dest;
		const wchar_t *src_ptr = src;

		while (n--) {
			dest_ptr[n] = src_ptr[n];
		}
		return dest;
	} else {
		/* copy normally */
		return wmemcpy(dest, src, n);
	}
}
