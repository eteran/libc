
#ifndef SIGNBIT_20110831_H_
#define SIGNBIT_20110831_H_

#define signbit(x) (copysign(1.0, (x)) < 0.0)

#endif
