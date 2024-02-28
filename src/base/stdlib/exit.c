
#define _ELIBC_SOURCE
#include <stdlib.h>

/*------------------------------------------------------------------------------
// Name: exit
//----------------------------------------------------------------------------*/
void exit(int status) {
	/* call any functions registered with atexit */
	__elibc_doexit();

	_Exit(status);
}
