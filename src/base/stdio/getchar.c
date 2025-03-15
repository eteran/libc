
#define _ELIBC_SOURCE
#include <stdio.h>

/**
 * @brief Read a character from stdin
 *
 * @return the character read, or EOF on error
 */
int getchar(void) {
	return fgetc(stdin);
}
