
#ifndef _C_FPCLASSIFY_H_20221228_
#define _C_FPCLASSIFY_H_20221228_

_LIBC_BEGIN

_CONST int __elibc_fpclassify(double x);

#define fpclassify(arg) __elibc_fpclassify(arg)

_LIBC_END

#endif
