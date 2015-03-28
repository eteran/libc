
#ifndef FWIDE_20140316_H_
#define FWIDE_20140316_H_

#ifdef __cplusplus
extern "C" {
#endif

int __elibc_fwide(FILE *stream, int mode) __ELIBC_NOTHROW;
int fwide(FILE *stream, int mode) __ELIBC_NOTHROW;

#ifdef __cplusplus
}
#endif

#endif
