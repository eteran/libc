
#ifndef _MBSTATE_T_20140319_H_
#define _MBSTATE_T_20140319_H_

typedef struct {
	wchar_t      wc;
	unsigned int expected : 4,
                 seen     : 4;
} mbstate_t;

#endif
