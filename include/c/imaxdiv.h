
#ifndef _C_IMAXDIV_H_20081002_
#define _C_IMAXDIV_H_20081002_

_LIBC_BEGIN

typedef struct {
	intmax_t quot;
	intmax_t rem;
} imaxdiv_t;

_CONST imaxdiv_t imaxdiv(intmax_t numerator, intmax_t denominator) _NOEXCEPT;

_LIBC_END

#endif
