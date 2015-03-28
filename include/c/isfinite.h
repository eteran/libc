
#ifndef ISFINITE_20110831_H_
#define ISFINITE_20110831_H_

#ifndef isfinite
#define isfinite(x) (fpclassify(x) != FP_NAN && fpclassify(x) != FP_INFINITE)
#endif

#endif
