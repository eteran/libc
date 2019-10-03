
#ifndef SETJMP_20051228_H_
#define SETJMP_20051228_H_

_LIBC_BEGIN

int setjmp(jmp_buf env);

/* C90 - 7.6 setjmp is a macro */
#define setjmp setjmp

_LIBC_END

#endif
