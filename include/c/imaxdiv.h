
#ifndef IMAXDIV_20081002_H_
#define IMAXDIV_20081002_H_

_LIBC_BEGIN

typedef struct {
	intmax_t quot;
	intmax_t rem;
} imaxdiv_t;

imaxdiv_t imaxdiv(intmax_t numerator, intmax_t denominator) _NOEXCEPT;

_LIBC_END

#endif
