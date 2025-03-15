
#define _ELIBC_SOURCE
#include <wchar.h>

/**
 * @brief Convert a multibyte string to a wide-character string
 *
 * @param dest The destination wide-character string
 * @param src The source multibyte string
 * @param len The maximum number of wide-characters to be written
 * @param ps The conversion state
 * @return The number of wide-characters written, not including the
 * terminating null wide-character, or (size_t)-1 if an error occurred.
 * @note If dest is NULL, len is ignored, and the function returns the number of
 * wide-characters that would be written if dest was not NULL.
 */
size_t mbsrtowcs(wchar_t *dest, const char **src, size_t len, mbstate_t *ps) {
	_UNUSED(dest);
	_UNUSED(src);
	_UNUSED(len);
	_UNUSED(ps);

	/*
  If  dest  is  not  NULL,  the mbsrtowcs() function converts the multibyte string
  *src to a wide-character string starting at dest.  At most len wide-characters
  are written  to  dest.   The  shift  state  *ps  is updated.   The conversion is
  effectively performed by repeatedly calling mbrtowc(dest, *src, n, ps) where n
  is some positive number, as long as this call succeeds, and then incrementing
  dest by one and  *src  by the number of bytes consumed.  The conversion can stop
  for three reasons:

  1. An  invalid  multibyte  sequence  has  been  encountered.   In this case,
  *src is left pointing to the invalid multibyte sequence, (size_t) -1 is
  returned, and errno is set to EILSEQ.

  2. len non-L'\0' wide-characters have been stored at dest.  In this case, *src
  is left  pointing  to  the next  multibyte  sequence  to  be  converted,  and
  the  number  of wide-characters written to dest is returned.

  3. The multibyte string has been completely converted, including  the
  terminating  null  wide  character
  ('\0'),  which  has  the side effect of bringing back *ps to the initial state.
  In this case, *src is set to NULL, and the number of wide-characters written to
  dest, excluding the  terminating  null  wide-character, is returned.

  If  dest  is  NULL,  len is ignored, and the conversion proceeds as above,
  except that the converted wide-characters are not written out to memory, and
  that no length limit exists.

  In both of the above cases, if ps is NULL, a static anonymous state known only
  to the  mbsrtowcs()  function is used instead.

  The programmer must ensure that there is room for at least len wide-characters
  at dest.

  */

	/* TODO(eteran): implement this */
	return (size_t)-1;
}
