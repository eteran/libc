/* C89, C94, C99 Compliant */

#ifndef _SIGNAL_H_20051228_
#define _SIGNAL_H_20051228_

#include "c/c-config.h"

#include "arch_sig_atomic_t.h" /* sig_atomic_t */
#include "c/_sighandler_t.h"   /* __sighandler_t */

#define SIG_DFL _REINTERPRET_CAST(__sighandler_t, 0)
#define SIG_ERR _REINTERPRET_CAST(__sighandler_t, 1)
#define SIG_IGN _REINTERPRET_CAST(__sighandler_t, -1)

/* made to match Linux */
#define SIGABRT  6
#define SIGFPE   8
#define SIGILL   4
#define SIGINT   2
#define SIGQUIT  3
#define SIGSEGV  11
#define SIGTERM  15
#define SIGTSTP  20
#define SIGWINCH 28

#include "c/raise.h"
#include "c/signal.h"

#endif
