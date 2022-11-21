
#define _ELIBC_SOURCE
#include <assert.h>
#include <errno.h>
#include <limits.h>
#include <stdlib.h>
#include <wchar.h>
#include <wctype.h>

/*------------------------------------------------------------------------------
// Name:
//----------------------------------------------------------------------------*/
long long wcstoll(const wchar_t *_RESTRICT nptr, wchar_t **_RESTRICT endptr, int base) {
	typedef long long int T;

	T neg = 0;
	T ret = 0;
	int err = 0;

	/*
	 * The strtol() function converts the initial part of the string in nptr to
	 * an unsigned long integer value according to the given base, which must be
	 * between 2 and 36 inclusive, or be the special value 0.
	 */

	assert((base == 0) || (base >= 2 && base <= 36));

	/*
	 * The string must begin with an arbitrary amount of white space (as deter-
	 * mined by isspace(3)) followed by a single optional '+' or '-' sign. If
	 * base is zero or 16, the string may then include a '0x' prefix, and the
	 * number will be read in base 16; otherwise, a zero base is taken as 10
	 * (decimal) unless the next character is '0', in which case it is taken as 8
	 * (octal).
	 */

	while (iswspace((wint_t)*nptr)) {
		++nptr;
	}

	/* single optional sign */
	switch (*nptr) {
	case L'-':
		neg = 1;
		/* FALL THROUGH */
	case L'+':
		++nptr;
	}

	if (base == 16 || base == 0) {
		if (nptr[0] == L'0' && (nptr[1] == L'x' || nptr[1] == L'X')) {
			base = 16;
			nptr += 2;
		}
	}

	if (base == 8 || base == 0) {
		if (nptr[0] == L'0') {
			base = 8;
			++nptr;
		}
	}

	if (base == 0) {
		base = 10;
	}

	/*
	 * The remainder of the string is converted to an unsigned long int value in
	 * the obvious manner, stopping at the first character which is not a valid
	 * digit in the given base. (In bases above 10, the letter 'A' in either
	 * upper or lower case represents 10, 'B' represents 11, and so forth, with
	 * 'Z' representing 35.)
	 */

	while (*nptr != '\0') {

		const T old_ret = ret;
		const wchar_t c = *nptr;
		int digit;

		if (c >= L'A' && c <= L'Z') {
			if (((c - L'A') + 10) < base) {
				digit = (c - L'A') + 10;
			} else {
				break;
			}
		} else if (c >= L'a' && c <= L'z') {
			if (((c - L'a') + 10) < base) {
				digit = (c - L'a') + 10;
			} else {
				break;
			}
		} else if (c >= L'0' && c <= L'9') {
			if ((c - L'0') < base) {
				digit = (c - L'0');
			} else {
				break;
			}
		} else {
			/* completely invalid character */
			break;
		}

		/* calculate as negative so we can properly calculate LLONG_MIN
		 * but catch the overflow of LLONG_MAX + 1
		 */
		ret = (ret * (T)base) - (T)digit;
		if (ret > old_ret) {

			/* subtracting a value should NEVER increase the result
			 * unless an overflow occurred!
			 */
			err = ERANGE;
			ret = neg ? LLONG_MIN : LLONG_MAX;
		}
		++nptr;
	}

	/*
	 * If endptr is not NULL, strtol() stores the address of the first invalid
	 * character in *endptr. If there were no digits at all, strtol() stores
	 * the original value of nptr in *endptr (and returns 0). In particular, if
	 * *nptr is not '\0' but **endptr is '\0' on return, the entire string is
	 * valid.
	 */
	if (endptr) {
		*endptr = (wchar_t *)nptr;
	}

	/*
	 * The strtol() function returns the result of the conversion, unless
	 * the value would underflow or overflow. If an underflow occurs, strtol()
	 * returns LONG_MIN. If an overflow occurs, strtol() returns LONG_MAX. In
	 * both cases, errno is set to ERANGE. Precisely the same holds for
	 * strtoll() (with LLONG_MIN and LLONG_MAX instead of LONG_MIN and LONG_MAX).
	 */

	if (!err && ret == LLONG_MIN && !neg) {
		err = ERANGE;
		ret = neg ? LLONG_MIN : LLONG_MAX;
	}

	if (!err) {
		return neg ? ret : -ret;
	} else {
		errno = err;
		return ret;
	}
}
