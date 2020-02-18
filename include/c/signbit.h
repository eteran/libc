
#ifndef _C_SIGNBIT_H_20110831_
#define _C_SIGNBIT_H_20110831_

#define signbit(x) (copysign(1.0, (x)) < 0.0)

#endif
