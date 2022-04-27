
#define _ELIBC_SOURCE
#include <assert.h>
#include <errno.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

/*------------------------------------------------------------------------------
// Name: __elibc_properly_encoded_length
//----------------------------------------------------------------------------*/
static int __elibc_properly_encoded_length(wchar_t wc) {

	const unsigned long ch = wc;

	if (ch >= 0xd800 && ch < 0xe000) {
		/* reserved for use by UTF-16 surrogates */
		return -1;
	}

	/* return the expected encoding length */
	if (ch < 0x00000080) {
		return 1;
	} else if (ch < 0x00000800) {
		return 2;
	} else if (ch < 0x00010000) {
		return 3;
	} else if (ch < 0x00200000) {
		return 4;
	} else if (ch < 0x04000000) {
		return 5;
	} else if (ch < 0x80000000) {
		return 6;
	}

	return -1;
}

/*------------------------------------------------------------------------------
// Name: __elibc_mbrtowc_ascii
//----------------------------------------------------------------------------*/
static size_t __elibc_mbrtowc_ascii(wchar_t *_RESTRICT pwc, const char *_RESTRICT s) {
	/* C locale version */
	if (s) {
		const unsigned char ch = *s;

		if (ch & 0x80) {
			errno = EILSEQ;
			return (size_t)-1;
		}

		if (pwc) {
			*pwc = ch;
		}

		return ch != '\0';
	} else {
		return 0;
	}
}

/*------------------------------------------------------------------------------
// Name: __elibc_mbrtowc_utf8
//----------------------------------------------------------------------------*/
static size_t __elibc_mbrtowc_utf8(wchar_t *_RESTRICT pwc, const char *_RESTRICT s, size_t n, mbstate_t *ps) {
	/* xx_YY.UTF-8 version */

	static mbstate_t internal_ps = {0, 0, 0};

	mbstate_t *const state = ps ? ps : &internal_ps;

	if (s) {
		int count = 0; /* how many bytes has this run processed */

		/* NOTE(eteran): we don't need to special case the NUL character,
		 * because it will qualify as a 1 byte encoding
		 */
		while (n-- != 0) {
			const unsigned char ch = *s++;

			/* are we looking at the first character of the sequence ? */
			if (state->seen == 0) {

				if ((ch & 0x80) == 0) {
					/* 1 byte */
					state->wc = ch;
					state->expected = 1;
				} else if ((ch & 0xe0) == 0xc0) {
					/* 2 byte */
					state->wc = ch & 0x1f;
					state->expected = 2;
				} else if ((ch & 0xf0) == 0xe0) {
					/* 3 byte */
					state->wc = ch & 0x0f;
					state->expected = 3;
				} else if ((ch & 0xf8) == 0xf0) {
					/* 4 byte */
					state->wc = ch & 0x07;
					state->expected = 4;
				} else if ((ch & 0xfc) == 0xf8) {
					/* 5 byte */
					errno = EILSEQ;
					return (size_t)-1; /* Restricted by RFC 3629 */
				} else if ((ch & 0xfe) == 0xfc) {
					/* 6 byte */
					errno = EILSEQ;
					return (size_t)-1; /* Restricted by RFC 3629 */
				} else {
					errno = EILSEQ;
					return (size_t)-1;
				}

				state->seen = 1;
				count = 1;

			} else if (state->seen < state->expected) {
				if ((ch & 0xc0) == 0x80) {
					state->wc <<= 6;
					state->wc |= ch & 0x3f;
					/* increment the shift state */
					++state->seen;
					++count;
				} else {
					errno = EILSEQ;
					return (size_t)-1;
				}
			} else {
				errno = EILSEQ;
				return (size_t)-1;
			}

			/* if we have read enough characters, time to exit */
			if (state->seen == state->expected) {
				break;
			}
		}

		/* we had to stop early */
		if (state->seen != state->expected) {
			return (size_t)-2;
		}

		/* check for overlong and reserved sequences! */
		if (__elibc_properly_encoded_length(state->wc) != state->seen) {
			errno = EILSEQ;
			return (size_t)-1;
		}

		/* store the result */
		if (pwc) {
			*pwc = state->wc;
		}

		if (state->wc == '\0') {
			count = 0;
		}

		/* reset the shift state */
		state->expected = 0;
		state->seen = 0;
		state->wc = 0;

		return count;

	} else {
		const mbstate_t prev_state = *state;

		/* reset the shift state */
		state->expected = 0;
		state->seen = 0;
		state->wc = 0;

		/* we had to stop early */
		if (prev_state.seen != prev_state.expected) {
			errno = EILSEQ;
			return (size_t)-1;
		}

		return 0;
	}
}

/*------------------------------------------------------------------------------
// Name: mbrtowc
//----------------------------------------------------------------------------*/
size_t mbrtowc(wchar_t *_RESTRICT pwc, const char *_RESTRICT s, size_t n, mbstate_t *ps) {

	const int locale_type = __elibc_get_locale_type(LC_CTYPE);

	switch (locale_type) {
	case _ELIBC_ASCII:
		return __elibc_mbrtowc_ascii(pwc, s);
	case _ELIBC_UTF8:
		return __elibc_mbrtowc_utf8(pwc, s, n, ps);
	default:
		return (size_t)-1;
	}
}
