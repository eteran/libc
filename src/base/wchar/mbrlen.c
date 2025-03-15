
#define _ELIBC_SOURCE
#include <assert.h>
#include <wchar.h>

/**
 * @brief Get the length of a multibyte character
 *
 * @param s the multibyte character to be checked
 * @param n maximum number of bytes to be examined
 * @param ps pointer to the multibyte conversion state
 * @return number of bytes in the multibyte character, or (size_t)-2
 * if an incomplete multibyte character was encountered, or (size_t)-1
 */
size_t mbrlen(const char *_RESTRICT s, size_t n, mbstate_t *_RESTRICT ps) {

	static _Thread_local mbstate_t state;
	assert(s);
	return mbrtowc(0, s, n, ps ? ps : &state);
}
