
#define __ELIBC_SOURCE
#include <string.h>
#include <stdint.h>

/*------------------------------------------------------------------------------
// Name: memmove
//----------------------------------------------------------------------------*/
void *memmove(void *dest, const void *src, size_t n) {

	if(dest == src) {
		return dest;
	}

	if((uintptr_t)dest > (uintptr_t)src) {
		/* copy backwards */
		char *dest_ptr      = dest;
		const char *src_ptr = src;

		while(n--) {
			dest_ptr[n] = src_ptr[n];
		}
		return dest;
	} else {
		/* copy normally */
		return memcpy(dest, src, n);
	}
}
