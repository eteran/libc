
#define __ELIBC_SOURCE
#include <stdio.h>

/*------------------------------------------------------------------------------
// Name: putchar
//----------------------------------------------------------------------------*/
int putchar(int c) {
	return fputc(c, stdout);
}