
#define __ELIBC_SOURCE
#define __STDC_LIMIT_MACROS
#include <assert.h>
#include <inttypes.h>
#include <stddef.h>
#include <stdint.h>

/*------------------------------------------------------------------------------
// Name: imaxabs
//----------------------------------------------------------------------------*/
intmax_t imaxabs(intmax_t j) {
	assert(j != INTMAX_MIN);
	return (j >= 0) ? j : -j;
}
