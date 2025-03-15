
#define _ELIBC_SOURCE
#include <stdio.h>

/**
 * @brief Write a character to standard output
 *
 * @param c the character to write
 * @return the character written, or EOF on error
 */
int putchar(int c) {
	return fputc(c, stdout);
}
