
#ifndef _C_FILE_H_20051228_
#define _C_FILE_H_20051228_

#define __ELIBC_FILE_STATIC_ALLOC 0x01 /* the allocation is tracked seperately for internal and general data */
#define __ELIBC_FILE_DEL_ON_CLOSE 0x02

struct _IO_FILE;

struct __elibc_internal_file_data {
	int           fd;
	int           buf_mod;
	unsigned      err         : 1,
                  eof         : 1,
				  orientation : 2; /* 0 = unset, 1 = invalid, 2 = char, 3 = wchar */
	unsigned int  flags;

	/* buffer managment */
	char *        buffer_ptr;
	unsigned long buffer_capacity;
	char *        buffer_first;
	char *        buffer_last;
	char *        internal_buffer_ptr; /* only set if the stdio library
                                        * allocated the buffer, so we can free
                                        * it later on fclose
                                        */
	char filename[1];
};

typedef struct _IO_FILE {
	/* so we can iterate through these efficiently */
	struct _IO_FILE *next;
	struct _IO_FILE *prev;

	/* actual FILE struct data, we do it this way for simple swapping of file handles */
	struct __elibc_internal_file_data *internal_data;
} FILE;

#define _FDATA(f) ((f)->internal_data)

#endif
