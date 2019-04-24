
#define __ELIBC_SOURCE
#include <stdlib.h>
#include <signal.h>

#ifdef __KERNEL__
#include <sys/panic.h>
#endif

/*
 * TODO(eteran):
 *
 * The abort() first unblocks the SIGABRT signal, and then raises that signal
 * for the calling process. This results in the abnormal termination of the
 * process unless the SIGABRT signal is caught and the signal handler does
 * not return (see longjmp(3)).
 *
 * If the abort() function causes process termination, all open streams are
 * closed and flushed.
 *
 * If the SIGABRT signal is ignored, or caught by a handler that returns, the
 * abort() function will still terminate the process. It does this by restoring
 * the default disposition for SIGABRT and then raising the signal for a second
 * time.
 */

/*------------------------------------------------------------------------------
// Name: abort
//----------------------------------------------------------------------------*/
void abort(void) {
#ifdef __KERNEL__
	/* in kernel mode version, this is same as a panic...bad */
	panic("abort");
#else
	raise(SIGABRT);
	exit(-127);
#endif
	while(1);
}
