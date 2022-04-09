
#ifndef _C_C94_WARNING_H_20200218_
#define _C_C94_WARNING_H_20200218_

/* requires c94, but we'll accept c++ for sanity's sake */
#if !defined(__cplusplus) && !defined(_HAS_C94) && !defined(_ELIBC_SOURCE)
#error "this header requires a C94 standard compiler or newer."
#endif

#endif
