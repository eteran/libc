
#ifndef FILENO_20061013_H_
#define FILENO_20061013_H_

/* NOTE: POSIX, not C */

#define __ELIBC_FILENO(stream) (_FDATA(stream)->fd)

#ifdef _POSIX_C_SOURCE
#define fileno(stream) __ELIBC_FILENO(stream)
#endif

#endif
