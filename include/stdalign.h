/* C89, C94, C99 Compliant */

#ifndef _STDALIGN_H_20130922_
#define _STDALIGN_H_20130922_

#include "c/c-config.h"

/* C++11 keywords */
#ifndef __cplusplus
#include "c/_c11_warning.h"
#define alignas _Alignas
#define alignof _Alignof
#endif

#define __alignas_is_defined 1
#define __alignof_is_defined 1

#endif
