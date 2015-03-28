
#ifndef ISUNORDERED_20140711_H_
#define ISUNORDERED_20140711_H_

#ifndef isunordered
#define isunordered(x,y) (isnan((x)) ? ((void)(y),1) : isnan((y)))
#endif

#endif
