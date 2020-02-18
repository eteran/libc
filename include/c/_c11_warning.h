
#ifndef _C_C11_WARNING_H_20200218_
#define _C_C11_WARNING_H_20200218_

/* requires c11, but we'll accept c++ for sanity's sake */
#if !defined(__cplusplus) && !defined(_HAS_C11) && !defined(__ELIBC_SOURCE)
#error "this header requires a C11 standard compiler or newer."
#endif

#endif
