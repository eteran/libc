/* C89, C94, C99 Compliant */

#ifndef _TIME_H_20051228_
#define _TIME_H_20051228_

#include "c/c-config.h"

/* POSIX says so */
#define CLOCKS_PER_SEC 1000000

#include "arch_size_t.h" /* size_t */
#include "c/_null.h"     /* NULL */
#include "c/_time.h"     /* clock_t, time_t, struct tm */

#include "c/asctime.h"
#include "c/clock.h"
#include "c/ctime.h"
#include "c/difftime.h"
#include "c/gmtime.h"
#include "c/localtime.h"
#include "c/mktime.h"
#include "c/strftime.h"
#include "c/time.h"

#endif
