
#define _ELIBC_SOURCE
#include <locale.h>
#include <stdlib.h>

/* system specific */
#include <asm/auxvec.h>
#include <elf.h>

#include "c/_support.h"

#ifdef __x86_64
typedef Elf64_auxv_t auxv_t;
#else
typedef Elf32_auxv_t auxv_t;
#endif

char **__elibc_environment = 0;

extern int main(int, char *[], char *[]);
_Noreturn void __elibc_init(int argc, char *argv[], char *envp[]);

/**
 * @brief Scans the auxiliary vector for specific information.
 *
 * @param envp The environment pointer, which is used to access the auxiliary vector.
 */
static void __elibc_scan_auxv(char *envp[]) {
	/* skip the envp and get to the auxv */
	while (*envp++) {
	}

	{
		const auxv_t *auxv = (void *)envp;

		while (auxv->a_type != AT_NULL) {
			if (auxv->a_type == AT_SYSINFO) {
				/* TODO(eteran): now what? */
			}
			++auxv;
		}
	}
}

/**
 * @brief Initializes the C runtime library.
 *
 * @param argc The number of command-line arguments.
 * @param argv An array of command-line arguments.
 * @param envp An array of environment variables.
 * @note This function sets up the environment, initializes the heap, sets the locale, and calls the main function.
 */
void __elibc_init(int argc, char *argv[], char *envp[]) {

	/* store the environment */
	__elibc_environment = envp;
	__elibc_scan_auxv(envp);
	__elibc_init_heap();

	setlocale(LC_ALL, "C");
	exit(main(argc, argv, envp));
}
