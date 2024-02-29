
#define _ELIBC_SOURCE
#include "c/_support.h"
#include <stdlib.h>

/*------------------------------------------------------------------------------
// Name: system
//----------------------------------------------------------------------------*/
int system(const char *command) {
	return __elibc_system(command);
}
