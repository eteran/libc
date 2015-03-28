
#ifndef LDIV_20051228_H_
#define LDIV_20051228_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	long quot;
	long rem;
} ldiv_t;

ldiv_t ldiv(long numerator, long denominator) __ELIBC_NOTHROW;

#ifdef __cplusplus
}
#endif

#endif
