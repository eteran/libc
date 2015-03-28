
#ifndef __C11_WARNING_H_
#define __C11_WARNING_H_

/* requires c11, but we'll accept c++ for sanity's sake */
#if !defined(__cplusplus) && !defined(__ISOC11_SOURCE) && !defined(__ELIBC_SOURCE)
#error "this header requires a C11 standard compiler or newer."
#endif

#endif
