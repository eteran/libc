
#define _ELIBC_SOURCE
#include <wchar.h>

/*------------------------------------------------------------------------------
// Name: mbsrtowcs
//----------------------------------------------------------------------------*/
size_t mbsrtowcs(wchar_t *dest, const char **src, size_t len, mbstate_t *ps) {
	(void)dest;
	(void)src;
	(void)len;
	(void)ps;

	/*
  If  dest  is  not  NULL,  the mbsrtowcs() function converts the multibyte string
  *src to a wide-character string starting at dest.  At most len wide characters
  are written  to  dest.   The  shift  state  *ps  is updated.   The conversion is
  effectively performed by repeatedly calling mbrtowc(dest, *src, n, ps) where n
  is some positive number, as long as this call succeeds, and then incrementing
  dest by one and  *src  by the number of bytes consumed.  The conversion can stop
  for three reasons:

  1. An  invalid  multibyte  sequence  has  been  encountered.   In this case,
  *src is left pointing to the invalid multibyte sequence, (size_t) -1 is
  returned, and errno is set to EILSEQ.

  2. len non-L'\0' wide characters have been stored at dest.  In this case, *src
  is left  pointing  to  the next  multibyte  sequence  to  be  converted,  and
  the  number  of wide characters written to dest is returned.

  3. The multibyte string has been completely converted, including  the
  terminating  null  wide  character
  ('\0'),  which  has  the side effect of bringing back *ps to the initial state.
  In this case, *src is set to NULL, and the number of wide characters written to
  dest, excluding the  terminating  null  wide character, is returned.

  If  dest  is  NULL,  len is ignored, and the conversion proceeds as above,
  except that the converted wide characters are not written out to memory, and
  that no length limit exists.

  In both of the above cases, if ps is NULL, a static anonymous state known only
  to the  mbsrtowcs()  func- tion is used instead.

  The programmer must ensure that there is room for at least len wide characters
  at dest.

  */
	return (size_t)-1;
}
