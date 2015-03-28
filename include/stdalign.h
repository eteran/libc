/* C89, C94, C99 Compliant */

#ifndef STDALIGN_20130922_H_
#define STDALIGN_20130922_H_

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
