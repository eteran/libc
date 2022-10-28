
#ifndef _C_ISLESSGREATER_H_20221028_
#define _C_ISLESSGREATER_H_20221028_

_LIBC_BEGIN

/* TODO(eteran): handle NaNs */
#define islessgreater(x, y) (x < y || x > y)

_LIBC_END

#endif
