
#ifndef ISNORMAL_20110831_H_
#define ISNORMAL_20110831_H_

#ifndef isnormal
#define isnormal(x) (fpclassify(x) == FP_NORMAL)
#endif

#endif
