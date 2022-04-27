#undef NDEBUG
#define _ELIBC_SOURCE
#include <assert.h>
#include <signal.h>
#include <stdio.h>

static volatile sig_atomic_t signal_status;

static void signal_handler(int signal) {
	signal_status = signal;
	assert(0);
}

int main(void) {
	signal(SIGINT, signal_handler);
#if 0
	raise(SIGINT);
	assert(signal_status == SIGINT);
#endif
	return 0;
}
