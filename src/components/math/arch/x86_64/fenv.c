#define _ELIBC_SOURCE
#include <fenv.h>
#include <stdint.h>

#define FNINIT() __asm__ __volatile__("fninit")

#define FPU_GETCW(cw) __asm__ __volatile__("fnstcw %0" \
										   : "=m"(cw))
#define FPU_SETCW(cw) __asm__ __volatile__("fldcw %0" \
										   :          \
										   : "m"(cw))

#define FPU_GETSW(sw) __asm__ __volatile__("fnstsw %0" \
										   : "=m"(sw))

#define FPU_GETENV(envp) __asm__ __volatile__("fnstenv %0" \
											  : "=m"(envp))
#define FPU_SETENV(envp) __asm__ __volatile__("fldenv %0" \
											  :           \
											  : "m"(envp))

#ifdef __SSE_MATH__
#define SSE_GETCW(xcw) __asm__ __volatile__("stmxcsr %0" \
											: "=m"(xcw))
#define SSE_SETCW(xcw) __asm__ __volatile__("ldmxcsr %0" \
											:            \
											: "m"(xcw))
#else
#define SSE_GETCW(xcw) \
	do {               \
		(xcw) = 0;     \
	} while (0)
#define SSE_SETCW(xcw) \
	do {               \
		_UNUSED(xcw);  \
	} while (0)
#endif

/*------------------------------------------------------------------------------
// Name:
// Desc:
//----------------------------------------------------------------------------*/
_ALWAYS_INLINE _INLINE static void __elibc_feclearexcept_fpu(int excepts) {
	fenv_t envp;
	FPU_GETENV(envp);
	envp.__status_word &= (unsigned short)(~(excepts & FE_ALL_EXCEPT));
	FPU_SETENV(envp);
}

/*------------------------------------------------------------------------------
// Name:
// Desc:
//----------------------------------------------------------------------------*/
_ALWAYS_INLINE _INLINE static void __elibc_feclearexcept_sse(int excepts) {
	uint32_t xcw;
	SSE_GETCW(xcw);
	xcw &= (uint32_t)(~(excepts & FE_ALL_EXCEPT));
	SSE_SETCW(xcw);
}

/*------------------------------------------------------------------------------
// Name: feclearexcept
// Desc:
//----------------------------------------------------------------------------*/
int feclearexcept(int excepts) {
	__elibc_feclearexcept_fpu(excepts);
	__elibc_feclearexcept_sse(excepts);
	return 0;
}

/*------------------------------------------------------------------------------
// Name:
// Desc:
//----------------------------------------------------------------------------*/
_ALWAYS_INLINE _INLINE static void __elibc_fesetround_fpu(int round) {

	uint16_t cw;
	FPU_GETCW(cw);
	cw = (uint16_t)((cw & (uint16_t)(~_ELIBC_FE_ROUND_MASK)) | (round & _ELIBC_FE_ROUND_MASK));
	FPU_SETCW(cw);
}

/*------------------------------------------------------------------------------
// Name:
// Desc:
//----------------------------------------------------------------------------*/
_ALWAYS_INLINE _INLINE static void __elibc_fesetround_sse(int round) {
	uint32_t xcw;
	SSE_GETCW(xcw);
	xcw = (xcw & 0x9fff) | (uint16_t)(round << 3);
	SSE_SETCW(xcw);
}

/*------------------------------------------------------------------------------
// Name: fesetround
//----------------------------------------------------------------------------*/
int fesetround(int round) {

	/* make sure that only rounding bits have been set */
	if ((round & ~_ELIBC_FE_ROUND_MASK) != 0) {
		return 1;
	}

	__elibc_fesetround_fpu(round);
	__elibc_fesetround_sse(round);
	return 0;
}

/*------------------------------------------------------------------------------
// Name:
// Desc:
//----------------------------------------------------------------------------*/
_ALWAYS_INLINE _INLINE static int __elibc_fegetround_fpu(void) {
	uint16_t cw;
	FPU_GETCW(cw);
	return cw & _ELIBC_FE_ROUND_MASK;
}

/*------------------------------------------------------------------------------
// Name: fegetround
// Note: we set it the same for SSE and FPU, so we'll just fetch from FPU only
//----------------------------------------------------------------------------*/
int fegetround(void) {
	return __elibc_fegetround_fpu();
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

	if (envp == FE_DFL_ENV) {
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
// Name:
// Desc:
//----------------------------------------------------------------------------*/
_ALWAYS_INLINE _INLINE static void __elibc_feraiseexcept_fpu(int excepts) {
	fenv_t envp;
	/* NOTE(eteran): this temp is to avoid a spurious warning on GCC-9.4.0
	 * where it things there's a conversion error even after casting :-/
	 */
	unsigned short temp;
	FPU_GETENV(envp);
	temp = (excepts & FE_ALL_EXCEPT);
	envp.__status_word |= temp;
	FPU_SETENV(envp);
}

/*------------------------------------------------------------------------------
// Name:
// Desc:
//----------------------------------------------------------------------------*/
_ALWAYS_INLINE _INLINE static void __elibc_feraiseexcept_sse(int excepts) {
	uint32_t xcw;
	SSE_GETCW(xcw);
	xcw |= (excepts & FE_ALL_EXCEPT);
	SSE_SETCW(xcw);
}

/*------------------------------------------------------------------------------
// Name: feraiseexcept
//----------------------------------------------------------------------------*/
int feraiseexcept(int excepts) {

	__elibc_feraiseexcept_fpu(excepts);
	__elibc_feraiseexcept_sse(excepts);
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

	return (int)(xcw | sw) & excepts;
}
