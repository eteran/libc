
#define _ELIBC_SOURCE
#include <signal.h>
#include <stdlib.h>

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

/**
 * @brief Terminate the program abnormally
 *
 */
void abort(void) {
	raise(SIGABRT);
	exit(-127);

	while (1) {
		;
	}
}
