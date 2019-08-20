
#define __ELIBC_SOURCE
#include <stdlib.h>

/*------------------------------------------------------------------------------
// Name: __ctype_get_mb_cur_max
//----------------------------------------------------------------------------*/
size_t __ctype_get_mb_cur_max(void) {
	/* TODO(eteran): make this depend on the current locale */
	/* UTF-8 only supports up to at most 4-bytes */
	return 4;
}
