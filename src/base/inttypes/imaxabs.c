
#define _ELIBC_SOURCE
#define __STDC_LIMIT_MACROS
#include <assert.h>
#include <inttypes.h>
#include <stddef.h>
#include <stdint.h>

/**
 * @brief Calculates the absolute value of an integer of type intmax_t.
 *
 * @param j The integer value to calculate the absolute value of.
 * @return Returns the absolute value of the input integer.
 */
intmax_t imaxabs(intmax_t j) {
	assert(j != INTMAX_MIN);
	return (j >= 0) ? j : -j;
}
