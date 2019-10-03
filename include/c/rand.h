
#ifndef RAND_20051228_H_
#define RAND_20051228_H_

_LIBC_BEGIN

int rand(void) _NOEXCEPT;
int rand_r(unsigned int *seedp) _NOEXCEPT;

unsigned int *__elibc_rand_next(void);

_LIBC_END

#endif
