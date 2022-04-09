
#define __ELIBC_SOURCE
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef STDIN_FILENO
#define STDIN_FILENO 0 /* Standard input.  */
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
	0,
	0,
	0,
	0,
	0,
	{""}};

static struct __elibc_internal_file_data __elibc_stdout_internal = {
	STDOUT_FILENO,
	_IOLBF,
	0,
	0,
	0,
	__ELIBC_FILE_STATIC_ALLOC,
	0,
	0,
	0,
	0,
	0,
	{""}};

static struct __elibc_internal_file_data __elibc_stderr_internal = {
	STDERR_FILENO,
	_IONBF,
	0,
	0,
	0,
	__ELIBC_FILE_STATIC_ALLOC,
	0,
	0,
	0,
	0,
	0,
	{""}};

FILE __elibc_stdin[1] = {
	{__elibc_stdout,
	 0,
	 &__elibc_stdin_internal
#if defined(USE_THREADS)
	 , PTHREAD_MUTEX_INITIALIZER
#endif
	}
};

FILE __elibc_stdout[1] = {
	{__elibc_stderr,
	 __elibc_stdin,
	 &__elibc_stdout_internal
#if defined(USE_THREADS)
	 , PTHREAD_MUTEX_INITIALIZER
#endif
	}
};

FILE __elibc_stderr[1] = {
	{0,
	 __elibc_stdout,
	 &__elibc_stderr_internal
#if defined(USE_THREADS)
	 , PTHREAD_MUTEX_INITIALIZER
#endif
	}
};

/* this is the root of our linked list of open file objects */
FILE *__elibc_root_file_struct = __elibc_stdin;
FILE *__elibc_free_file_struct = NULL;

void __elibc_lock_stream(FILE *stream) {
	assert(stream);
#if defined(USE_THREADS)
	pthread_mutex_lock(&stream->mutex);
#endif
	(void)stream;
}

void __elibc_unlock_stream(FILE *stream) {
	assert(stream);
#if defined(USE_THREADS)
	pthread_mutex_unlock(&stream->mutex);
#endif
	(void)stream;
}

/* NOTE(eteran): we use this caching strategy of FILE objects for two reasons
 * 1. because it's faster than reaching out to malloc
 * 2. more importantly, by delaying actually freeing the objects, it makes
 * it MUCH easier to deal with future locking strategies. Since we want to
 * store the mutex IN the FILE object, but we also want to wrap the fclose
 * operation in that same mutex
 */
FILE *__elibc_allocate_file(void) {

	if(__elibc_free_file_struct) {
		FILE *stream = __elibc_free_file_struct;
		__elibc_free_file_struct = stream->next;
		if(__elibc_free_file_struct) {
			__elibc_free_file_struct->prev = NULL;
		}
		return stream;
	}

	return malloc(sizeof(FILE));
}

void __elibc_free_file(FILE *stream) {
	stream->next = __elibc_free_file_struct;
	stream->prev = NULL;
	if(__elibc_free_file_struct) {
		__elibc_free_file_struct->prev = stream;
	}
	__elibc_free_file_struct = stream;
}
