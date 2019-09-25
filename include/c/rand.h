
#ifndef RAND_20051228_H_
#define RAND_20051228_H_

#ifdef __cplusplus
extern "C" {
#endif

int rand(void) _NOEXCEPT;
int rand_r(unsigned int *seedp) _NOEXCEPT;

unsigned int *__elibc_rand_next(void);

#ifdef __cplusplus
}
#endif

#endif
