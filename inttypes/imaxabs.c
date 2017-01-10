
#define __ELIBC_SOURCE
#define __STDC_LIMIT_MACROS
#include <stddef.h>
#include <inttypes.h>
#include <stdint.h>
#include <assert.h>

/*------------------------------------------------------------------------------
// Name: imaxabs
//----------------------------------------------------------------------------*/
intmax_t imaxabs(intmax_t j) {
	assert(j != INTMAX_MIN);
	return (j >= 0) ? j : -j;
}
