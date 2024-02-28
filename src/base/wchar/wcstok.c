
#define _ELIBC_SOURCE
#include <wchar.h>

/*------------------------------------------------------------------------------
// Name: wcstok
//----------------------------------------------------------------------------*/
wchar_t *wcstok(wchar_t *_RESTRICT s, const wchar_t *_RESTRICT delim) {
	static _Thread_local wchar_t *ptr = 0;
	return wcstok_r(s, delim, &ptr);
}

/*------------------------------------------------------------------------------
// Name: wcstok_r
//----------------------------------------------------------------------------*/
wchar_t *wcstok_r(wchar_t *_RESTRICT s, const wchar_t *_RESTRICT delim, wchar_t **ptrptr) {

	wchar_t *start;

	if (s) {
		/* if s != 0 then we consider this the "first call" */
		*ptrptr = s;
	}

	start = *ptrptr;

	if (start) {
		/* skip first delimiters */
		start += wcsspn(*ptrptr, delim);

		/* did we find a non-delimiter */
		if (start) {
			/* find the end of this token */
			wchar_t *end = wcspbrk(start + 1, delim);

			/* if it did not end at the end of the string, replace
			   that delimiter with a NULL terminator */
			if (end) {
				*end++ = L'\0';
			}
			*ptrptr = end;
		}
	}
	return start;
}
