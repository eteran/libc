
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdio.h>

/*------------------------------------------------------------------------------
// Name: gets
//----------------------------------------------------------------------------*/
char *gets(char *s) {
	char *s_ptr = s;

	assert(s);

	while (1) {
		const int ch = getchar();
		if (ch == '\n' || ch == EOF) {
			break;
		}
		*s_ptr++ = (char)ch;
	}

	*s_ptr = '\0';

	return s;
}
