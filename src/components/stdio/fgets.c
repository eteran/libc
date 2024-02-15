
#define _ELIBC_SOURCE
#include <stdio.h>
#include <assert.h>

/*------------------------------------------------------------------------------
// Name: __elibc_fgets
//----------------------------------------------------------------------------*/
static char *__elibc_fgets(char *_RESTRICT s, int size, FILE *_RESTRICT stream) {
	char *s_ptr = s;

	if (size > 1) {
		while (--size) {
			const int ch = __elibc_fgetc(stream);

			if (ch != EOF) {
				*s_ptr++ = (char)ch;
			}

			if (ch == EOF && s_ptr == s) {
				/* TODO(eteran): NUL terminate this buffer? */
				return NULL;
			}

			if (ch == EOF || ch == '\n') {
				break;
			}
		}

		*s_ptr = '\0';
	}

	return s;
}

/*------------------------------------------------------------------------------
// Name: fgets
//----------------------------------------------------------------------------*/
char *fgets(char *_RESTRICT s, int size, FILE *_RESTRICT stream) {
	char *r;
	__ELIBC_WITH_LOCK(__elibc_fgets(s, size, stream), &r);
	return r;
}
