
#define _ELIBC_SOURCE
#include <wchar.h>

/**
 * @brief Split a wide string into tokens
 *
 * @param s the wide string to be split
 * @param delim the delimiter characters
 * @return pointer to the next token in the string, or NULL if there are no more tokens
 * @note This function is not thread-safe. Use wcstok_r instead.
 */
wchar_t *wcstok(wchar_t *_RESTRICT s, const wchar_t *_RESTRICT delim) {
	static _Thread_local wchar_t *ptr = 0;
	return wcstok_r(s, delim, &ptr);
}

/**
 * @brief Split a wide string into tokens (thread-safe)
 *
 * @param s the wide string to be split
 * @param delim the delimiter characters
 * @param saveptr pointer to a wchar_t* where the function will store the next position in the string
 * @return pointer to the next token in the string, or NULL if there are no more tokens
 */
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
