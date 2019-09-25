
#ifndef __C94_WARNING_H_
#define __C94_WARNING_H_

/* requires c94, but we'll accept c++ for sanity's sake */
#if !defined(__cplusplus) && !defined(_HAS_C94) && !defined(__ELIBC_SOURCE)
#error "this header requires a C94 standard compiler or newer."
#endif

#endif
