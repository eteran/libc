
#ifndef _C_FILE_H_20051228_
#define _C_FILE_H_20051228_

#if defined(_ELIBC_USE_THREADS)
#include <pthread.h>
#endif

#define _ELIBC_FILE_STATIC_ALLOC 0x01 /* don't delete object on close */

#define _ELIBC_FILE_ORIENTATION_NONE    0
#define _ELIBC_FILE_ORIENTATION_INVALID 1
#define _ELIBC_FILE_ORIENTATION_NARROW  2
#define _ELIBC_FILE_ORIENTATION_WIDE    3

struct _IO_FILE;

struct __elibc_file {
	int fd;
	int buf_mod;
	unsigned err : 1;
	unsigned eof : 1;
	unsigned char orientation;
	unsigned char flags;

	/* buffer management */
	char *buffer_start;
	char *buffer_end;
	char *buffer_first;        /* start of used buffer portion */
	char *buffer_last;         /* end of used buffer portion*/
	char *internal_buffer_ptr; /* only set if the stdio library
								* allocated the buffer, so we can free
								* it later on fclose
								*/
};

typedef struct _IO_FILE {
	/* so we can iterate through these efficiently */
	struct _IO_FILE *next;
	struct _IO_FILE *prev;

	/* actual FILE struct data, we do it this way for simple swapping of file
	 * handles */
	struct __elibc_file *internal;

#if defined(_ELIBC_USE_THREADS)
	pthread_mutex_t mutex;
#endif
} FILE;

#define _FDATA(f) ((f)->internal)

#define _ELIBC_STREAM_BUFFER_SIZE(stream) ((size_t)(_FDATA(stream)->buffer_end - _FDATA(stream)->buffer_start))

#define _ELIBC_ALLOCATE_FILE_BUFFER(stream)                    \
	do {                                                       \
		char *const buffer                  = malloc(BUFSIZ);  \
		_FDATA(stream)->buffer_start        = buffer;          \
		_FDATA(stream)->buffer_first        = buffer;          \
		_FDATA(stream)->buffer_last         = buffer;          \
		_FDATA(stream)->buffer_end          = buffer + BUFSIZ; \
		_FDATA(stream)->internal_buffer_ptr = buffer;          \
	} while (0)

#endif
