
#define _ELIBC_SOURCE
#include <assert.h>
#include <wchar.h>

/**
 * @brief Copies n wide-characters from the source string to the destination string.
 *
 * @param dest The destination string where the wide-characters will be copied to.
 * @param src The source string from which the wide-characters will be copied.
 * @param n The number of wide-characters to copy.
 * @return wchar_t* Returns a pointer to the destination string after copying the wide-characters.
 */
wchar_t *wmemcpy(wchar_t *_RESTRICT dest, const wchar_t *_RESTRICT src, size_t n) {

	/* traditional memory copy */
	wchar_t *d_ptr       = dest;
	const wchar_t *s_ptr = src;

	assert(dest);
	assert(src);

	while (n--) {
		*d_ptr++ = *s_ptr++;
	}

	return dest;
}
