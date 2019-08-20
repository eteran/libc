
#define __ELIBC_SOURCE
#include <string.h>

/*------------------------------------------------------------------------------
// Name: strcpy
//----------------------------------------------------------------------------*/
char *strcpy(char *__ELIBC_RESTRICT dest, const char *__ELIBC_RESTRICT src) {
	char *dest_ptr = dest;

	while(*src != '\0') {
		*dest_ptr++ = *src++;
	}

	*dest_ptr = '\0';
	return dest;
}
