
#define __ELIBC_SOURCE
#include <string.h>

/*------------------------------------------------------------------------------
// Name: strncpy
//----------------------------------------------------------------------------*/
char *strncpy(char *__ELIBC_RESTRICT dest, const char *__ELIBC_RESTRICT src, size_t n) {

	char *dest_ptr = dest;


	while(n && (*src != '\0')) {
		*dest_ptr++ = *src++;
		--n;
	}

	while(n--) {
		*dest_ptr++ = '\0';
	}

	return dest;

}
