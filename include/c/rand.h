
#ifndef RAND_20051228_H_
#define RAND_20051228_H_

#ifdef __cplusplus
extern "C" {
#endif

int rand(void) __ELIBC_NOTHROW;
int rand_r(unsigned int *seedp) __ELIBC_NOTHROW;

unsigned int *__elibc_rand_next(void);

#ifdef __cplusplus
}
#endif

#endif
