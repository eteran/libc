
#ifndef _C_NULL_H_20051228_
#define _C_NULL_H_20051228_

#ifdef __cplusplus
	#ifdef __GNUC__
		#define NULL __null
	#else
		#define NULL 0
	#endif
#else
    #define NULL ((void*)0)
#endif

#endif
