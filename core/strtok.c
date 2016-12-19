
#define __ELIBC_SOURCE
#include <string.h>

/*------------------------------------------------------------------------------
// Name: strtok
//----------------------------------------------------------------------------*/
char *strtok(char *__ELIBC_RESTRICT s, const char *__ELIBC_RESTRICT delim) {
	_Thread_local static char *ptr = 0;
	return strtok_r(s, delim, &ptr);
}

/*------------------------------------------------------------------------------
// Name: strtok_r
//----------------------------------------------------------------------------*/
char *strtok_r(char *__ELIBC_RESTRICT s, const char *__ELIBC_RESTRICT delim, char **ptrptr) {

	char *start;

	if(s) {
		/* if s != 0 then we consider this the "first call" */
		*ptrptr = s;
	}

	start = *ptrptr;

	if(start) {
		/* skip first delimiters */
		start += strspn(*ptrptr, delim);

		/* did we find a non-delimiter */
		if(start) {
			/* find the end of this token */
			char *end = strpbrk(start + 1, delim);

			/* if it did not end at the end of the string, replace
			   that delimiter with a NULL terminator */
			if(end) {
				*end++ = '\0';
			}
			*ptrptr = end;
		}
	}
	return start;
}
