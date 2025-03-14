
#define _ELIBC_SOURCE
#define _ELIBC_SAFE_STRING
#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

/**
 * @brief Get a string describing an error code
 *
 * @param errnum the error code
 * @param buf the buffer to store the error message
 * @param n the size of the buffer
 * @return int 0 on success, or a non-zero value on failure
 */
int strerror_r(int errnum, char *buf, size_t n) {

	assert(buf);

	switch (errnum) {
	case 0:
		strlcpy(buf, "Success", n);
		break;
	case EPERM:
		strlcpy(buf, "Operation not permitted", n);
		break;
	case ERANGE:
		strlcpy(buf, "Numerical result out of range", n);
		break;
	case ENOENT:
		strlcpy(buf, "No such file or directory", n);
		break;
	case ESRCH:
		strlcpy(buf, "No such process", n);
		break;
	case EINTR:
		strlcpy(buf, "Interrupted system call", n);
		break;
	case EIO:
		strlcpy(buf, "Input/output error", n);
		break;
	case ENXIO:
		strlcpy(buf, "No such device or address", n);
		break;
	case E2BIG:
		strlcpy(buf, "Argument list too long", n);
		break;
	case ENOEXEC:
		strlcpy(buf, "Exec format error", n);
		break;
	case EBADF:
		strlcpy(buf, "Bad file descriptor", n);
		break;
	case ECHILD:
		strlcpy(buf, "No child processes", n);
		break;
	case EAGAIN:
		strlcpy(buf, "Resource temporarily unavailable", n);
		break;
	case ENOMEM:
		strlcpy(buf, "Cannot allocate memory", n);
		break;
	case EACCES:
		strlcpy(buf, "Permission denied", n);
		break;
	case EFAULT:
		strlcpy(buf, "Bad address", n);
		break;
	case ENOTBLK:
		strlcpy(buf, "Block device required", n);
		break;
	case EBUSY:
		strlcpy(buf, "Device or resource busy", n);
		break;
	case EEXIST:
		strlcpy(buf, "File exists", n);
		break;
	case EXDEV:
		strlcpy(buf, "Invalid cross-device link", n);
		break;
	case ENODEV:
		strlcpy(buf, "No such device", n);
		break;
	case ENOTDIR:
		strlcpy(buf, "Not a directory", n);
		break;
	case EISDIR:
		strlcpy(buf, "Is a directory", n);
		break;
	case EINVAL:
		strlcpy(buf, "Invalid argument", n);
		break;
	case ENFILE:
		strlcpy(buf, "Too many open files in system", n);
		break;
	case EMFILE:
		strlcpy(buf, "Too many open files", n);
		break;
	case ENOTTY:
		strlcpy(buf, "Inappropriate ioctl for device", n);
		break;
	case ETXTBSY:
		strlcpy(buf, "Text file busy", n);
		break;
	case EFBIG:
		strlcpy(buf, "File too large", n);
		break;
	case ENOSPC:
		strlcpy(buf, "No space left on device", n);
		break;
	case ESPIPE:
		strlcpy(buf, "Illegal seek", n);
		break;
	case EROFS:
		strlcpy(buf, "Read-only file system", n);
		break;
	case EMLINK:
		strlcpy(buf, "Too many links", n);
		break;
	case EPIPE:
		strlcpy(buf, "Broken pipe", n);
		break;
	case EDOM:
		strlcpy(buf, "Numerical argument out of domain", n);
		break;
	case EILSEQ:
		strlcpy(buf, "Invalid or incomplete multibyte or wide-character", n);
		break;
	case EOWNERDEAD:
		strlcpy(buf, "Owner died", n);
		break;
	case ENOTRECOVERABLE:
		strlcpy(buf, "State not recoverable", n);
		break;
	default:
		snprintf(buf, n, "Unknown error %d", errnum);
		break;
	}

	return 0;
}

/**
 * @brief Get a string describing an error code
 *
 * @param errnum the error code
 * @return char* pointer to a string describing the error code
 * @note This function is not thread-safe. Use strerror_r instead.
 */
char *strerror(int errnum) {
	static _Thread_local char errstr[0x100];
	strerror_r(errnum, errstr, sizeof(errstr));
	return errstr;
}
