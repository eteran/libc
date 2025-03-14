
#define _ELIBC_SOURCE
#include <stdlib.h>

/**
 * @brief Exit the program with the specified status
 *
 * @param status the exit status of the program
 */
void exit(int status) {
	/* call any functions registered with atexit */
	__elibc_doexit();

	_Exit(status);
}
