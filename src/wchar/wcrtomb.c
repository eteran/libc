
#define __ELIBC_SOURCE
#include <assert.h>
#include <wchar.h>

/*------------------------------------------------------------------------------
// Name: wcrtomb
//----------------------------------------------------------------------------*/
size_t wcrtomb(char *s, wchar_t wc, mbstate_t *ps) {

	const unsigned long ch = wc;

	(void)ps;

	assert(s);

	if (ch >= 0xd800 && ch < 0xe000) {
		/* reserved for use by UTF-16 surrogates */
		return -1;
	}

	if (ch < 0x00000080) {
		s[0] = (ch & 0x7f);
		return 1;

	} else if (ch < 0x00000800) {
		s[0] = 0xc0 | ((ch >> 6) & 0x1f);
		s[1] = 0x80 | ((ch >> 0) & 0x3f);
		return 2;

	} else if (ch < 0x00010000) {
		s[0] = 0xe0 | ((ch >> 12) & 0x0f);
		s[1] = 0x80 | ((ch >> 6) & 0x3f);
		s[2] = 0x80 | ((ch >> 0) & 0x3f);
		return 3;

	} else if (ch < 0x00200000) {
		s[0] = 0xf0 | ((ch >> 18) & 0x07);
		s[1] = 0x80 | ((ch >> 12) & 0x3f);
		s[2] = 0x80 | ((ch >> 6) & 0x3f);
		s[3] = 0x80 | ((ch >> 0) & 0x3f);
		return 4;

	} else if (ch < 0x04000000) {
		s[0] = 0xf8 | ((ch >> 24) & 0x03);
		s[1] = 0x80 | ((ch >> 18) & 0x3f);
		s[2] = 0x80 | ((ch >> 12) & 0x3f);
		s[3] = 0x80 | ((ch >> 6) & 0x3f);
		s[4] = 0x80 | ((ch >> 0) & 0x3f);
		return 5;

	} else if (ch < 0x80000000) {
		s[0] = 0xfc | ((ch >> 30) & 0x01);
		s[1] = 0x80 | ((ch >> 24) & 0x3f);
		s[2] = 0x80 | ((ch >> 18) & 0x3f);
		s[3] = 0x80 | ((ch >> 12) & 0x3f);
		s[4] = 0x80 | ((ch >> 6) & 0x3f);
		s[5] = 0x80 | ((ch >> 0) & 0x3f);
		return 6;
	}

	return (size_t)-1;
}
