/* C89, C94, C99 Compliant */

#ifndef SIGNAL_20051228_H_
#define SIGNAL_20051228_H_

#include "c/c-config.h"
#include "c/_sighandler_t.h" /* __sighandler_t */
#include "arch_sig_atomic_t.h"  /* sig_atomic_t */

#define SIG_DFL ((__sighandler_t)0)
#define SIG_ERR ((__sighandler_t)1)
#define SIG_IGN ((__sighandler_t)-1)

/* made to match Linux */
#define SIGABRT 6
#define SIGFPE  8
#define SIGILL  4
#define SIGINT  2
#define SIGQUIT 3
#define SIGSEGV 11
#define SIGTERM 15
#define SIGTSTP 20
#define SIGWINCH 28

#include "c/signal.h"
#include "c/raise.h"

#endif
