
#ifndef _C_ISINF_H_20110831_
#define _C_ISINF_H_20110831_

#ifndef isinf
#define isinf(x) ((x) != 0.0 && (x) + (x) == (x))
#endif

#endif
