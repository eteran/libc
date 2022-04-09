
#ifndef _C_C99_WARNING_H_20200218_
#define _C_C99_WARNING_H_20200218_

/* requires c99, but we'll accept c++ for sanity's sake */
#if !defined(__cplusplus) && !defined(_HAS_C99) && !defined(_ELIBC_SOURCE)
#error "this header requires a C99 standard compiler or newer."
#endif

#endif
