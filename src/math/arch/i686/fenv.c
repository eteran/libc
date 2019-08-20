
#define __ELIBC_SOURCE
#include <fenv.h>
#include <stdint.h>

/* TODO(eteran):
int feclearexcept(int excepts);
int fegetexceptflag(fexcept_t *flagp, int excepts);
int feraiseexcept(int excepts);
int fesetexceptflag(const fexcept_t *flagp, int excepts);
int fetestexcept(int excepts);
int fegetround(void);
int fegetenv(fenv_t *envp);
int feholdexcept(fenv_t *envp);
int fesetenv(const fenv_t *envp);
int feupdateenv(const fenv_t *envp);
*/

/*------------------------------------------------------------------------------
// Name: fesetround 
//----------------------------------------------------------------------------*/
int fesetround (int round) {
	uint16_t cw;

	if ((round & ~0xc00) != 0) {
		return 1;
	}

	__asm__ __volatile__ ("fnstcw %0" : "=m" (*&cw));
	cw &= ~0xc00;
	cw |= round;
	__asm__ __volatile__ ("fldcw %0" : : "m" (*&cw));

#if 0
	/* If the CPU supports SSE we set the MXCSR as well.  */
	if ((GLRO(dl_hwcap) & HWCAP_I386_XMM) != 0) {
		unsigned int xcw;
		__asm__ ("stmxcsr %0" : "=m" (*&xcw));
		xcw &= ~0x6000;
		xcw |= round << 3;
		__asm__ ("ldmxcsr %0" : : "m" (*&xcw));
	}
#endif
	return 0;
}
