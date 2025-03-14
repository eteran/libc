
#define _ELIBC_SOURCE
#include <wchar.h>

/**
 * @brief Splits a wide string into tokens
 *
 * @param s The wide string to split
 * @param delim The delimiters to use for splitting the string
 * @return wchar_t* The next token in the string, or NULL if there are no more tokens
 * @note This function uses a static buffer to store the current position in the string, so it is not thread-safe
 */
wchar_t *wcstok(wchar_t *_RESTRICT s, const wchar_t *_RESTRICT delim) {
	static _Thread_local wchar_t *ptr = 0;
	return wcstok_r(s, delim, &ptr);
}

/**
 * @brief Splits a wide string into tokens
 *
 * @param s The wide string to split
 * @param delim The delimiters to use for splitting the string
 * @param ptrptr A pointer to a wide-character pointer used as the current position in the string
 * @return wchar_t* The next token in the string, or NULL if there are no more tokens
 * @note This function is thread-safe
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
