
#ifndef ARCH_STDARCH_20100128_H_
#define ARCH_STDARCH_20100128_H_

/* there are some inherant assumptions and limitations that come along with
   the stdarg technique, the most basic of which is that arguments must be
   in order linearly in memory and stack aligned, also no arguments may be
   passed via registers, as that would violate the first rule, after that, 
   easy pickings ;)
*/

#include "arch_va_list.h"

/* TODO: make this arch specific */
#define __elibc_stacktype long

/* this is used to make sure types are aligned properly */
#define __elibc_va_size(type) \
	((sizeof(type) + sizeof(__elibc_stacktype) - 1) & ~(sizeof(__elibc_stacktype) - 1))

/* simply one element past the last argument */
#define va_start(ap, last) \
	do { \
		((ap) = ((((va_list)&(last))) + __elibc_va_size(last))); \
	} while(0)

/* zero out ap to invalidate it */
#define va_end(ap) \
	do { \
		((ap) = 0);\
	} while(0)

/* increment the pointer, and then get the pointer at what it was */
#define va_arg(ap, type) \
	(ap = (va_list) ((char *) (ap) + __elibc_va_size (type)), \
	*((type *) (void *) ((char *) (ap) - __elibc_va_size (type))))
	
#define __elibc_va_copy(d, s) \
	do { \
		(d) = (s);\
	} while(0)

#endif
