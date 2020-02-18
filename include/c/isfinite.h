
#ifndef _C_ISFINITE_H_20110831_
#define _C_ISFINITE_H_20110831_

#ifndef isfinite
#define isfinite(x) (fpclassify(x) != FP_NAN && fpclassify(x) != FP_INFINITE)
#endif

#endif
