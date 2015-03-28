
#ifndef SETJMP_20051228_H_
#define SETJMP_20051228_H_

#ifdef __cplusplus
extern "C" {
#endif

int setjmp(jmp_buf env);

/* C90 - 7.6 setjmp is a macro */
#define setjmp setjmp

#ifdef __cplusplus
}
#endif

#endif
