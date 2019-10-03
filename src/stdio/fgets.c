
#define __ELIBC_SOURCE
#include <stdio.h>

/*------------------------------------------------------------------------------
// Name: __elibc_fgets
//----------------------------------------------------------------------------*/
static char *__elibc_fgets(char *_RESTRICT s, int size, FILE *_RESTRICT stream) {
	char *s_ptr = s;

	if(size > 1) {
		while(--size) {
			const int ch = __elibc_fgetc(stream);

			if(ch != EOF) {
				*s_ptr++ = ch;
			}

			if(ch == EOF && s_ptr == s) {
				/* TODO(eteran): NUL terminate this buffer? */
				return NULL;
			}

			if(ch == EOF || ch == '\n') {
				break;
			}
		}

		*s_ptr = '\0';
	}

	/* TODO(eteran): I've seen at least one implementation that NUL terminates even
	 * with a size of 0, check with the standard
	 */
	return s;
}

/*------------------------------------------------------------------------------
// Name: fgets
//----------------------------------------------------------------------------*/
char *fgets(char *_RESTRICT s, int size, FILE *_RESTRICT stream) {
	char *r;
	__elibc_lock_stream(stream);
	r = __elibc_fgets(s, size, stream);
	__elibc_unlock_stream(stream);
	return r;
}
