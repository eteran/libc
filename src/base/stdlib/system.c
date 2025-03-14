
#define _ELIBC_SOURCE
#include "c/_support.h"
#include <stdlib.h>

/**
 * @brief Execute a shell command
 *
 * @param command the command to execute
 * @return int the exit status of the command
 */
int system(const char *command) {
	return __elibc_system(command);
}
