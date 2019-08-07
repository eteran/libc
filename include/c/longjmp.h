
#ifndef LONGJMP_20051228_H_
#define LONGJMP_20051228_H_

#ifdef __cplusplus
extern "C" {
#endif

_Noreturn void longjmp(jmp_buf env, int val);

#ifdef __cplusplus
}
#endif

#endif
