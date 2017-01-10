
#define __ELIBC_SOURCE
#include <stdio.h>

/*------------------------------------------------------------------------------
// Name: __elibc_fgets
//----------------------------------------------------------------------------*/
char *__elibc_fgets(char *__ELIBC_RESTRICT s, int size, FILE *__ELIBC_RESTRICT stream) {
	char *s_ptr = s;

	if(size > 1) {
		while(--size) {
			const int ch = __elibc_fgetc(stream);

			if(ch != EOF) {
				*s_ptr++ = ch;
			}

			if(ch == EOF && s_ptr == s) {
				/* TODO: NUL terminate this buffer? */
				return NULL;
			}

			if(ch == EOF || ch == '\n') {
				break;
			}
		}

		*s_ptr = '\0';
	}

	/* TODO: I've seen at least one implementation that NUL terminates even
	 * with a size of 0, check with the standard
	 */

	return s;
}

/*------------------------------------------------------------------------------
// Name: fgets
//----------------------------------------------------------------------------*/
char *fgets(char *__ELIBC_RESTRICT s, int size, FILE *__ELIBC_RESTRICT stream) {
	char *r;
	__elibc_lock_stream(stream);
	r = fgets(s, size, stream);
	__elibc_unlock_stream(stream);
	return r;
}
