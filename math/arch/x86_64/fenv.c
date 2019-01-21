
/* TODO: confirm correctness of these functions */

#define __ELIBC_SOURCE
#include <fenv.h>
#include <stdint.h>

#define FNINIT() __asm__ __volatile__ ("fninit")

#define FPU_GETCW(cw) __asm__ __volatile__ ("fnstcw %0" : "=m" (cw))
#define FPU_SETCW(cw) __asm__ __volatile__ ("fldcw %0" : : "m" (cw))

#define FPU_GETSW(sw) __asm__ __volatile__ ("fnstsw %0" : "=m" (sw))

#define FPU_GETENV(envp) __asm__ __volatile__ ("fnstenv %0" : "=m" (envp))
#define FPU_SETENV(envp) __asm__ __volatile__ ("fldenv %0"  : : "m" (envp))

#ifdef __SSE_MATH__
#define SSE_GETCW(xcw) __asm__ __volatile__ ("stmxcsr %0" : "=m" (xcw))
#define SSE_SETCW(xcw) __asm__ __volatile__ ("ldmxcsr %0" : : "m" (xcw))
#else
#define SSE_GETCW(xcw) do {} while(0)
#define SSE_SETCW(xcw) do {} while(0)
#endif

/*------------------------------------------------------------------------------
// Name: feclearexcept 
// Desc:
// Note: what about SSE exceptions?
//----------------------------------------------------------------------------*/
int feclearexcept(int excepts) {

	fenv_t envp;
	FPU_GETENV(envp);
	envp.__status_word &= ~(excepts & FE_ALL_EXCEPT);
	FPU_SETENV(envp);
	return 0;
}

/*------------------------------------------------------------------------------
// Name: fesetround 
//----------------------------------------------------------------------------*/
int fesetround(int round) {

	uint16_t cw;

	/* make sure that only rounding bits have been set */
	if ((round & ~__ELIBC_FE_ROUND_MASK) != 0) {
		return 1;
	}

	/* set it for the FPU */
	FPU_GETCW(cw);
	cw = (cw & ~__ELIBC_FE_ROUND_MASK) | round;
	FPU_SETCW(cw);

	/* set it for SSE */
	{
		uint32_t xcw;
		SSE_GETCW(xcw);
		xcw = (xcw & ~0x6000) | (round << 3);
		SSE_SETCW(xcw);
	}
	return 0;
}

/*------------------------------------------------------------------------------
// Name: fegetround
// Note: we set it the same for SSE and FPU, so we'll just fetch from FPU only
//----------------------------------------------------------------------------*/
int fegetround(void) {
	uint16_t cw;
	FPU_GETCW(cw);
	return cw & __ELIBC_FE_ROUND_MASK;
}

/*------------------------------------------------------------------------------
// Name: fegetenv 
//----------------------------------------------------------------------------*/
int fegetenv(fenv_t *envp) {

	FPU_GETENV(*envp);
	SSE_GETCW(envp->__mxcsr);
	return 0;
}

/*------------------------------------------------------------------------------
// Name: fesetenv 
//----------------------------------------------------------------------------*/
int fesetenv(const fenv_t *envp) {

	if(envp == FE_DFL_ENV) {
		const uint32_t xcw = 0x1f80;
		FNINIT();
		SSE_SETCW(xcw);
	} else {
		FPU_SETENV(*envp);
		SSE_SETCW(envp->__mxcsr);
	}
	return 0;
}

/*------------------------------------------------------------------------------
// Name: feraiseexcept 
//----------------------------------------------------------------------------*/
int feraiseexcept(int excepts) {
	uint32_t xcw;
	SSE_GETCW(xcw);
	xcw |= (excepts & FE_ALL_EXCEPT);
	SSE_SETCW(xcw);
	return 0;
}

/*------------------------------------------------------------------------------
// Name: fetestexcept 
//----------------------------------------------------------------------------*/
int fetestexcept(int excepts) {

	uint32_t xcw;
	uint16_t sw;

	excepts &= FE_ALL_EXCEPT;
	SSE_GETCW(xcw);
	FPU_GETSW(sw);
	
	return (xcw | sw) & excepts;
}




