
#define _ELIBC_SOURCE
#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stdlib.h>

/*------------------------------------------------------------------------------
// Name: strtoul
//----------------------------------------------------------------------------*/
unsigned long int strtoul(const char *nptr, char **endptr, int base) {
	typedef unsigned long int T;

	T neg = 0;
	T ret = 0;
	int err = 0;

	/*
	 * The strtoul() function converts the initial part of the string in nptr to
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

	while (isspace(*nptr)) {
		++nptr;
	}

	/* single optional sign */
	switch (*nptr) {
	case '-':
		neg = 1;
		/* FALL THROUGH */
	case '+':
		++nptr;
	}

	if (base == 16 || base == 0) {
		if (nptr[0] == '0' && (nptr[1] == 'x' || nptr[1] == 'X')) {
			base = 16;
			nptr += 2;
		}
	}

	if (base == 8 || base == 0) {
		if (nptr[0] == '0') {
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
		const char c = *nptr;
		unsigned int digit;

		if (c >= 'A' && c <= 'Z') {
			if (((c - 'A') + 10) < base) {
				digit = (c - 'A') + 10;
			} else {
				break;
			}
		} else if (c >= 'a' && c <= 'z') {
			if (((c - 'a') + 10) < base) {
				digit = (c - 'a') + 10;
			} else {
				break;
			}
		} else if (c >= '0' && c <= '9') {
			if ((c - '0') < base) {
				digit = (c - '0');
			} else {
				break;
			}
		} else {
			/* completely invalid character */
			break;
		}

		ret = (ret * base) + digit;
		if (ret < old_ret) {

			/* adding a value should NEVER decrease the result
			 * unless an overflow occured!
			 */
			err = ERANGE;
			ret = ULONG_MAX;
		}
		++nptr;
	}

	/*
	 * If endptr is not NULL, strtoul() stores the address of the first invalid
	 * character in *endptr. If there were no digits at all, strtoul() stores
	 * the original value of nptr in *endptr (and returns 0). In particular, if
	 * *nptr is not '\0' but **endptr is '\0' on return, the entire string is
	 * valid.
	 */
	if (endptr) {
		*endptr = (char *)nptr;
	}

	/*
	 * The strtoul() function returns either the result of the conversion or,
	 * if there was a leading minus sign, the negation of the result of the
	 * conversion represented as an unsigned value, unless the original
	 * (non-negated) value would overflow; in the latter case, strtoul()
	 * returns ULONG_MAX and sets the global variable errno to ERANGE.
	 * Precisely the same holds for strtoull() (with ULLONG_MAX instead of
	 * ULONG_MAX).
	 */

	/* NOTE: No need to special case the overflow with negation, it is covered
	 * by the primary check above
	 */

	if (!err) {
		return neg ? -ret : ret;
	} else {
		errno = err;
		return ret;
	}
}
