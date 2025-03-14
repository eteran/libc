
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdint.h>
#include <wchar.h>

/**
 * @brief Convert a wide-character to a multibyte character
 *
 * @param s destination multibyte character string
 * @param wc wide-character to be converted
 * @param ps conversion state information
 * @return size_t number of bytes written, or (size_t)-1 if an error occurred
 * @note s must be at least MB_CUR_MAX bytes long
 */
size_t wcrtomb(char *s, wchar_t wc, mbstate_t *ps) {

	const unsigned long ch = (unsigned long)wc;
	unsigned char *s_ptr   = (unsigned char *)s;

	_UNUSED(ps);

	_Static_assert(sizeof(unsigned long) >= sizeof(wchar_t), "unsupported wchar_t size");

	assert(s);

	if (ch >= 0xd800 && ch < 0xe000) {
		/* reserved for use by UTF-16 surrogates */
		return (size_t)-1;
	}

	if (ch < 0x00000080) {
		s_ptr[0] = (ch & 0x7f);
		return 1;

	} else if (ch < 0x00000800) {
		s_ptr[0] = (uint8_t)(0xc0 | ((ch >> 6) & 0x1f));
		s_ptr[1] = (uint8_t)(0x80 | ((ch >> 0) & 0x3f));
		return 2;

	} else if (ch < 0x00010000) {
		s_ptr[0] = (uint8_t)(0xe0 | ((ch >> 12) & 0x0f));
		s_ptr[1] = (uint8_t)(0x80 | ((ch >> 6) & 0x3f));
		s_ptr[2] = (uint8_t)(0x80 | ((ch >> 0) & 0x3f));
		return 3;

	} else if (ch < 0x00200000) {
		s_ptr[0] = (uint8_t)(0xf0 | ((ch >> 18) & 0x07));
		s_ptr[1] = (uint8_t)(0x80 | ((ch >> 12) & 0x3f));
		s_ptr[2] = (uint8_t)(0x80 | ((ch >> 6) & 0x3f));
		s_ptr[3] = (uint8_t)(0x80 | ((ch >> 0) & 0x3f));
		return 4;

	} else if (ch < 0x04000000) {
		s_ptr[0] = (uint8_t)(0xf8 | ((ch >> 24) & 0x03));
		s_ptr[1] = (uint8_t)(0x80 | ((ch >> 18) & 0x3f));
		s_ptr[2] = (uint8_t)(0x80 | ((ch >> 12) & 0x3f));
		s_ptr[3] = (uint8_t)(0x80 | ((ch >> 6) & 0x3f));
		s_ptr[4] = (uint8_t)(0x80 | ((ch >> 0) & 0x3f));
		return 5;

	} else if (ch < 0x80000000) {
		s_ptr[0] = (uint8_t)(0xfc | ((ch >> 30) & 0x01));
		s_ptr[1] = (uint8_t)(0x80 | ((ch >> 24) & 0x3f));
		s_ptr[2] = (uint8_t)(0x80 | ((ch >> 18) & 0x3f));
		s_ptr[3] = (uint8_t)(0x80 | ((ch >> 12) & 0x3f));
		s_ptr[4] = (uint8_t)(0x80 | ((ch >> 6) & 0x3f));
		s_ptr[5] = (uint8_t)(0x80 | ((ch >> 0) & 0x3f));
		return 6;
	}

	return (size_t)-1;
}
