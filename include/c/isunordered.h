
#ifndef _C_ISUNORDERED_H_20140711_
#define _C_ISUNORDERED_H_20140711_

#ifndef isunordered
#define isunordered(x,y) (isnan((x)) ? ((void)(y),1) : isnan((y)))
#endif

#endif
