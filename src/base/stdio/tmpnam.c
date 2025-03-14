
#define _ELIBC_SOURCE
#include <stdio.h>
#include <stdlib.h>

/* TODO(eteran): what standard defines this? */
#define P_tmpnam "/tmp/"

/**
 * @brief Generate a unique temporary filename
 *
 * @param s a pointer to a buffer to store the filename in, or NULL to use a static buffer
 * @return a pointer to the generated filename, or NULL if the limit of TMP_MAX has been reached
 * @note s must be at least L_tmpnam bytes long
 */
char *tmpnam(char *s) {
	char *p = 0;
	static _Thread_local char buf[L_tmpnam];
	static _Thread_local int limit = 0;

	if (limit < TMP_MAX) {
		++limit;
		p = (!s) ? buf : s;

		do {
			static const char alphabet[] =
				"0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_-%";

			snprintf(p, L_tmpnam, "%s%s%c%c%c%c%c%c%c%c", P_tmpnam, "file",
					 alphabet[(size_t)rand() % (sizeof(alphabet) - 1)],
					 alphabet[(size_t)rand() % (sizeof(alphabet) - 1)],
					 alphabet[(size_t)rand() % (sizeof(alphabet) - 1)],
					 alphabet[(size_t)rand() % (sizeof(alphabet) - 1)],
					 alphabet[(size_t)rand() % (sizeof(alphabet) - 1)],
					 alphabet[(size_t)rand() % (sizeof(alphabet) - 1)],
					 alphabet[(size_t)rand() % (sizeof(alphabet) - 1)],
					 alphabet[(size_t)rand() % (sizeof(alphabet) - 1)]);

			/* TODO(eteran): change this while to a condition to test if the file
			 * exists, it is actually more probable then it looks because an unseeded
			 * rand() is the same for all processes, perhaps we should integrate the
			 * PID as well?
			 */
		} while (0);
	}

	return p;
}
