
#define _ELIBC_SOURCE
#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: strtod
// TODO(eteran): finish this code!
//----------------------------------------------------------------------------*/
double strtod(const char *_RESTRICT nptr, char **_RESTRICT endptr) {

	double sign             = 1.0;
	const char *radix_index = 0;
	double ret              = 0.0;

	assert(nptr);

	/*
	The  expected  form  of the (initial portion of the) string is optional
	leading white space as recognized by isspace(3), an optional plus ('+')
	or  minus  sign  ('-')  and then either (i) a decimal number, or (ii) a
	hexadecimal number, or (iii) an infinity, or (iv) a NAN (not-a-number).
	*/

	while (isspace(*nptr)) {
		++nptr;
	}

	/* single optional sign */
	switch (*nptr) {
	case '-':
		sign = -1.0;
		/* FALL THROUGH */
	case '+':
		++nptr;
	}

	/* An infinity is either "INF" or "INFINITY", disregarding case. */
	if (strcasecmp(nptr, "inf") == 0 || strcasecmp(nptr, "infinity") == 0) {
		return INFINITY;
	}

	/*
	A NAN is "NAN"  (disregarding  case)  optionally  followed  by  '(',  a
	sequence  of  characters, followed by ')'.  The character string specifies
	in an implementation-dependent way the type of NAN.
	*/
	if (strncasecmp(nptr, "nan", 3) == 0) {
		nptr += 3;
		if (*nptr == '(') {
			nptr = strchr(nptr, ')');
		}

		/* TODO(eteran): what do we pass here, if anything? */
		return NAN;
	}

	/*
	A decimal number consists of a nonempty sequence of decimal digits possibly
	containing a radix character  (decimal  point,  locale-dependent,
	usually  '.'),  optionally  followed  by a decimal exponent.  A decimal
	exponent consists of an 'E' or 'e', followed by  an  optional  plus  or
	minus  sign,  followed  by  a  nonempty sequence of decimal digits, and
	indicates multiplication by a power of 10.
	*/

	while (*nptr != '\0') {

		const char c = *nptr;

		if (isdigit(c)) {
			ret *= 10.0;
			ret += (c - '0');
		} else if (c == '.') { /* TODO(eteran): make this locale dependant */
			radix_index = nptr;
		} else {
			break;
		}
		++nptr;
	}

	/* did we see a radix, if so, account for it */
	if (radix_index) {
		ret /= pow(10.0, (double)(nptr - radix_index - 1));
	}

	/* ok, time for exponent processing */
	if (*nptr != '\0') {
		if (*nptr == 'E' || *nptr == 'e') {
			double exponent      = 0.0;
			double exponent_sign = 1.0;

			++nptr;

			switch (*nptr) {
			case '-':
				exponent_sign = -1.0;
				/* FALL THROUGH */
			case '+':
				++nptr;
			}

			while (*nptr != '\0') {

				const char c = *nptr;

				if (isdigit(c)) {
					exponent *= 10.0;
					exponent += (c - '0');
				} else {
					break;
				}
				++nptr;
			}

			ret *= pow(10, exponent * exponent_sign);
		}
	}

	/*
	A hexadecimal number consists of a "0x" or "0X" followed by a  nonempty
	sequence  of  hexadecimal digits possibly containing a radix character,
	optionally followed by a binary exponent.  A binary  exponent  consists
	of  a  'P' or 'p', followed by an optional plus or minus sign, followed
	by a nonempty sequence of decimal digits, and indicates  multiplication
	by  a  power of 2.  At least one of radix character and binary exponent
	must be present.
	*/

	if (endptr) {
		*endptr = (char *)nptr;
	}

	ret *= sign;

	return ret;
}

#endif
