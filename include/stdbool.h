/* C89, C94, C99 Compliant */

#ifndef STDBOOL_20051228_H_
#define STDBOOL_20051228_H_

#include "c/c-config.h"

/* C++11 keywords */
#ifndef __cplusplus
#include "c/_c99_warning.h"
#define bool  _Bool
#define true  (_Bool)1
#define false (_Bool)0
#endif

#define __bool_true_false_are_defined 1

#endif
