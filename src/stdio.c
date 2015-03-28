
#define __ELIBC_SOURCE
#include <stdio.h>
#include <assert.h>

#ifndef STDIN_FILENO
#define STDIN_FILENO  0 /* Standard input.  */
#endif

#ifndef STDOUT_FILENO
#define STDOUT_FILENO 1 /* Standard output.  */
#endif

#ifndef STDERR_FILENO
#define STDERR_FILENO 2 /* Standard error output.  */
#endif

static struct __elibc_internal_file_data __elibc_stdin_internal = {
	STDIN_FILENO,
	_IOLBF,
	0,
	0,
	0,
	__ELIBC_FILE_STATIC_ALLOC,
	0,0,0,0,0,
	{ "" }
};

static struct __elibc_internal_file_data __elibc_stdout_internal = {
	STDOUT_FILENO,
	_IOLBF,
	0,
	0,
	0,
	__ELIBC_FILE_STATIC_ALLOC,
	0,0,0,0,0,
	{ "" }
};

static struct __elibc_internal_file_data __elibc_stderr_internal = {
	STDERR_FILENO,
	_IONBF,
	0,
	0,
	0,
	__ELIBC_FILE_STATIC_ALLOC,
	0,0,0,0,0,
	{ "" }
};

extern FILE __elibc_stdin[1];
extern FILE __elibc_stdout[1];
extern FILE __elibc_stderr[1];

FILE __elibc_stdin[1] = {
	{
		__elibc_stdout,
		0,
		&__elibc_stdin_internal
	}
};

FILE __elibc_stdout[1] = {
	{
		__elibc_stderr,
		__elibc_stdin,
		&__elibc_stdout_internal
	}
};

FILE __elibc_stderr[1] = {
	{
		0,
		__elibc_stdout,
		&__elibc_stderr_internal
	}
};

/* standard C I/O file objects */
FILE *const stdin  = __elibc_stdin;
FILE *const stdout = __elibc_stdout;
FILE *const stderr = __elibc_stderr;

/* this is the root of our linked list of open file objects */
FILE *__elibc_root_file_struct = __elibc_stdin;

void __elibc_lock_stream(FILE *stream) {
	/* TODO: locking */
	assert(stream);
}

void __elibc_unlock_stream(FILE *stream) {
	/* TODO: unlocking */
	assert(stream);
}
