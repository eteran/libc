/* C89, C94, C99 Compliant */

#ifndef _STDIO_H_20051228_
#define _STDIO_H_20051228_

#include "c/c-config.h"

#include "arch_size_t.h" /* size_t */
#include "c/_file.h"     /* FILE   */
#include "arch_fpos_t.h" /* fpos_t */
#include "c/_null.h"     /* NULL   */

#define _IOFBF 0
#define _IOLBF 1
#define _IONBF 2

#define BUFSIZ       256
#define EOF          (-1)
#define FOPEN_MAX    16
#define FILENAME_MAX 256
#define L_tmpnam     20

#define SEEK_SET     0
#define SEEK_CUR     1
#define SEEK_END     2

#define TMP_MAX      0x7fff

extern FILE *__elibc_root_file_struct;
extern FILE __elibc_stdin[1];
extern FILE __elibc_stdout[1];
extern FILE __elibc_stderr[1];

/* standard C I/O file objects */
#define stdin  (__elibc_stdin)
#define stdout (__elibc_stdout)
#define stderr (__elibc_stderr)

/* prototypes for all necessary functions */
#include "c/remove.h"
#include "c/rename.h"
#include "c/tmpfile.h"
#include "c/tmpnam.h"
#include "c/fclose.h"
#include "c/fflush.h"
#include "c/fopen.h"
#include "c/freopen.h"
#include "c/setbuf.h"
#include "c/setvbuf.h"
#include "c/fprintf.h"
#include "c/fscanf.h"
#include "c/printf.h"
#include "c/scanf.h"
#include "c/sprintf.h"
#include "c/sscanf.h"
#include "c/vfprintf.h"
#include "c/vsprintf.h"
#include "c/fgetc.h"
#include "c/fgets.h"
#include "c/fputc.h"
#include "c/fputs.h"
#include "c/getc.h"
#include "c/getchar.h"
#include "c/gets.h"
#include "c/putc.h"
#include "c/putchar.h"
#include "c/puts.h"
#include "c/ungetc.h"
#include "c/fread.h"
#include "c/fwrite.h"
#include "c/fgetpos.h"
#include "c/fseek.h"
#include "c/fsetpos.h"
#include "c/ftell.h"
#include "c/rewind.h"
#include "c/clearerr.h"
#include "c/feof.h"
#include "c/ferror.h"
#include "c/perror.h"

#if defined(_HAS_C99) || defined(_HAS_CXX89) || defined(__ELIBC_SOURCE)
	#include "c/vprintf.h"
	#include "c/vsprintf.h"
	#include "c/vfprintf.h"
#endif

#if defined(_HAS_C99) || defined(_HAS_CXX11) || defined(__ELIBC_SOURCE)
	#include "c/snprintf.h"
	#include "c/vfscanf.h"
	#include "c/vscanf.h"
	#include "c/vsnprintf.h"
	#include "c/vsscanf.h"
#endif

/* POSIX only */
#include "c/fileno.h"

void __elibc_lock_stream(FILE *stream);
void __elibc_unlock_stream(FILE *stream);

#endif
