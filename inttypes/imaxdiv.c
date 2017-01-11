
#define __ELIBC_SOURCE
#define __STDC_LIMIT_MACROS
#include <stddef.h>
#include <inttypes.h>
#include <stdint.h>
#include <assert.h>

/*------------------------------------------------------------------------------
// Name: imaxdiv
//----------------------------------------------------------------------------*/
imaxdiv_t imaxdiv(intmax_t numerator, intmax_t denominator) {
	imaxdiv_t ret = { 0, 0 };
	
	assert(denominator != 0);
	
	/* On some platforms, we need to implement compiler support functions
	 * such as __moddi3 and __divdi3
	 */
	ret.quot = numerator / denominator;
	ret.rem  = numerator % denominator;
	return ret;
}
