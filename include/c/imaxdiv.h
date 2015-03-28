
#ifndef IMAXDIV_20081002_H_
#define IMAXDIV_20081002_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	intmax_t quot;
	intmax_t rem;
} imaxdiv_t;

imaxdiv_t imaxdiv(intmax_t numerator, intmax_t denominator) __ELIBC_NOTHROW;

#ifdef __cplusplus
}
#endif

#endif
