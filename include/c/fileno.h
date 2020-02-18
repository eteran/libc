
#ifndef _C_FILENO_H_20061013_
#define _C_FILENO_H_20061013_

/* NOTE: POSIX, not C */

#define __ELIBC_FILENO(stream) (_FDATA(stream)->fd)

#ifdef _POSIX_C_SOURCE
#define fileno(stream) __ELIBC_FILENO(stream)
#endif

#endif
