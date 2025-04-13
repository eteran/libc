
#ifndef _C_RAND_H_20051228_
#define _C_RAND_H_20051228_

_LIBC_BEGIN

int rand(void) _NOEXCEPT;
int rand_r(unsigned int *seedp) _NOEXCEPT _NON_NULL(1);

unsigned int *__elibc_rand_next(void);

_LIBC_END

#endif
