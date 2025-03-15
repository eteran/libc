
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdlib.h>

/**
 * @brief Divide two integers and return the quotient and remainder
 *
 * @param numerator the numerator of the division
 * @param denominator the denominator of the division
 * @return a structure containing the quotient and remainder of the division
 */
lldiv_t lldiv(long long numerator, long long denominator) {
	lldiv_t ret;

	assert(denominator);

	ret.quot = numerator / denominator;
	ret.rem  = numerator % denominator;
	return ret;
}
