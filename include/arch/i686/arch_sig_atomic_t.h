
#ifndef _ARCH_I686_ARCH_SIG_ATOMIC_T_H_20200218_
#define _ARCH_I686_ARCH_SIG_ATOMIC_T_H_20200218_

#if defined(__SIG_ATOMIC_TYPE__)
typedef __SIG_ATOMIC_TYPE__ sig_atomic_t;
#else
typedef volatile int sig_atomic_t;
#endif

#endif
