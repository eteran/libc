
#define __ELIBC_SOURCE
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

extern char **__elibc_environment;
char **__elibc_environment = 0;

extern int main(int, char *[], char *[]);

/*------------------------------------------------------------------------------
// Name: __elibc_scan_auxv
// Desc: 
//----------------------------------------------------------------------------*/
static void __elibc_scan_auxv(char *envp[]) {
	/* skip the envp and get to the auxv */
	while (*envp++) {
	}

	{
		const auxv_t *auxv = (void *)envp;

		while (auxv->a_type != AT_NULL) {
			if (auxv->a_type == AT_SYSINFO) {
				/* now what? */
			}
			++auxv;
		}
	}
}

/*------------------------------------------------------------------------------
// Name: __elibc_init
// Desc: this is the first C code which runs, it is _pre_ main and sets up a
//       sane environment, it will then call main and pass its return value
//       to exit.
//----------------------------------------------------------------------------*/
_Noreturn void __elibc_init(int argc, char *argv[], char *envp[]) {

	/* store the environment */
	__elibc_environment = envp;
	__elibc_scan_auxv(envp);
	__elibc_init_heap();

	setlocale(LC_ALL, "C");
	exit(main(argc, argv, envp));
}
