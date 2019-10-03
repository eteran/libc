
#define __ELIBC_SOURCE
#include <string.h>

/*------------------------------------------------------------------------------
// Name: strncat
//----------------------------------------------------------------------------*/
char *strncat(char *_RESTRICT dest, const char *_RESTRICT src, size_t n) {
	char *dest_ptr = dest;

	if (n != 0) {
		/* find the end of the string... */
		while (*dest_ptr != '\0') {
			++dest_ptr;
		}

		/* copy the new string to that location */
		while (n-- && *src != '\0') {
			*dest_ptr++ = *src++;
		}

		*dest_ptr = '\0';
	}

	/* return pointer to combined string */
	return dest;
}
