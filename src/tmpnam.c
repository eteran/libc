
#define __ELIBC_SOURCE
#include <stdio.h>
#include <stdlib.h>

/* TODO: what standard defines this? */
#define P_tmpnam "/tmp/"

/*------------------------------------------------------------------------------
// Name: tmpnam
//----------------------------------------------------------------------------*/
char *tmpnam(char *s) {
	char *p = 0;
	_Thread_local static char buf[L_tmpnam];
	_Thread_local static int limit = 0;

	if(limit < TMP_MAX) {
		++limit;
		p = (!s) ? buf : s;

		do {
			static const char alphabet[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_-%";

			snprintf(
				p,
				L_tmpnam,
				"%s%s%c%c%c%c%c%c%c%c",
				P_tmpnam,
				"file",
				alphabet[rand() % (sizeof(alphabet) - 1)],
				alphabet[rand() % (sizeof(alphabet) - 1)],
				alphabet[rand() % (sizeof(alphabet) - 1)],
				alphabet[rand() % (sizeof(alphabet) - 1)],
				alphabet[rand() % (sizeof(alphabet) - 1)],
				alphabet[rand() % (sizeof(alphabet) - 1)],
				alphabet[rand() % (sizeof(alphabet) - 1)],
				alphabet[rand() % (sizeof(alphabet) - 1)]
				);
				/* TODO: change this while to a condition to test if the file exists,
				 * it is actually more probable then it looks because an unseeded rand()
				 * is the same for all processes, perhaps we should integrate the PID
				 * as well?
				 */
		} while(0);
	}

	return p;

}
