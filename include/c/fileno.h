
#ifndef _C_FILENO_H_20061013_
#define _C_FILENO_H_20061013_

/* NOTE: POSIX, not C */

/* TODO(eteran): add locking to this */
#define _ELIBC_FILENO(stream) (_FDATA(stream)->fd)

#ifdef _POSIX_C_SOURCE
#define fileno(stream) _ELIBC_FILENO(stream)
#endif

#endif
