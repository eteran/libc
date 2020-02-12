
#define __ELIBC_SOURCE
#include <string.h>

/*------------------------------------------------------------------------------
// Name: strtok
//----------------------------------------------------------------------------*/
char *strtok(char *_RESTRICT s, const char *_RESTRICT delim) {
	static _Thread_local char *ptr = 0;
	return strtok_r(s, delim, &ptr);
}

/*------------------------------------------------------------------------------
// Name: strtok_r
//----------------------------------------------------------------------------*/
char *strtok_r(char *_RESTRICT s, const char *_RESTRICT delim, char **ptrptr) {

	char *start;

	if (s) {
		/* if s != 0 then we consider this the "first call" */
		*ptrptr = s;
	}

	start = *ptrptr;

	if (start) {
		/* skip first delimiters */
		start += strspn(*ptrptr, delim);

		/* did we find a non-delimiter */
		if (start) {
			/* find the end of this token */
			char *end = strpbrk(start + 1, delim);

			/* if it did not end at the end of the string, replace
			   that delimiter with a NULL terminator */
			if (end) {
				*end++ = '\0';
			}
			*ptrptr = end;
		}
	}
	return start;
}
