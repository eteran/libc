
#ifndef _NULL_20051228_H_
#define _NULL_20051228_H_

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
