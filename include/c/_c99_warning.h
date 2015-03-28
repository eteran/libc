
#ifndef __C99_WARNING_H_
#define __C99_WARNING_H_

/* requires c99, but we'll accept c++ for sanity's sake */
#if !defined(__cplusplus) && !defined(__ISOC99_SOURCE) && !defined(__ELIBC_SOURCE)
#error "this header requires a C99 standard compiler or newer."
#endif

#endif
