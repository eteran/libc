
#ifndef _C_ISNORMAL_H_20110831_
#define _C_ISNORMAL_H_20110831_

#ifndef isnormal
#define isnormal(x) (fpclassify(x) == FP_NORMAL)
#endif

#endif
