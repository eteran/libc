
#ifndef _C_SETJMP_H_20051228_
#define _C_SETJMP_H_20051228_

_LIBC_BEGIN

int setjmp(jmp_buf env);

/* C90 - 7.6 setjmp is a macro */
#define setjmp setjmp

_LIBC_END

#endif
