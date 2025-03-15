
#define _ELIBC_SOURCE
#include <assert.h>
#include <inttypes.h>
#include <stddef.h>
#include <stdint.h>

/**
 * @brief Performs integer division and returns both the quotient and remainder.
 *
 * @param numerator The numerator of the division.
 * @param denominator The denominator of the division.
 * @return Returns a structure containing the quotient and remainder of the division.
 */
imaxdiv_t imaxdiv(intmax_t numerator, intmax_t denominator) {
	imaxdiv_t ret;

	assert(denominator != 0);

	ret.quot = numerator / denominator;
	ret.rem  = numerator % denominator;
	return ret;
}
