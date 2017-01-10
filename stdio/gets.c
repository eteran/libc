
#define __ELIBC_SOURCE
#include <stdio.h>

/*------------------------------------------------------------------------------
// Name: gets
//----------------------------------------------------------------------------*/
char *gets(char *s) {
	char *s_ptr = s;
	char ch;

	while((ch = getchar()) != '\n') {
		*s_ptr++ = ch;
	}

	*s_ptr = '\0';

	return s;
}