
#define _ELIBC_SOURCE
#include <string.h>

/*------------------------------------------------------------------------------
// Name: strcat
//----------------------------------------------------------------------------*/
char *strcat(char *_RESTRICT dest, const char *_RESTRICT src) {
	char *dest_ptr = dest;

	/* find the end of the string... */
	while (*dest_ptr != '\0') {
		++dest_ptr;
	}

	/* copy the new string to that location */
	while (*src != '\0') {
		*dest_ptr++ = *src++;
	}

	*dest_ptr = '\0';

	/* return pointer to combined string */
	return dest;
}
