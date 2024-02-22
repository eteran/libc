cmake_minimum_required(VERSION 3.15)

add_library(c-wchar STATIC
	btowc.c
	fgetwc.c
	fgetws.c
	fputwc.c
	fputws.c
	fwide.c
	fwprintf.c
	fwscanf.c
	getwchar.c
	mbrlen.c
	mbrtowc.c
	mbsinit.c
	mbsrtowcs.c
	putwchar.c
	swprintf.c
	swscanf.c
	ungetwc.c
	vfwprintf.c
	vfwscanf.c
	vswprintf.c
	vswscanf.c
	vwprintf.c
	vwscanf.c
	wcrtomb.c
	wcscat.c
	wcschr.c
	wcscmp.c
	wcscoll.c
	wcscpy.c
	wcscspn.c
	wcsftime.c
	wcslen.c
	wcsncat.c
	wcsncmp.c
	wcsncpy.c
	wcspbrk.c
	wcsrchr.c
	wcsrtombs.c
	wcsspn.c
	wcsstr.c
	wcstod.c
	wcstof.c
	wcstok.c
	wcstol.c
	wcstold.c
	wcstoll.c
	wcstoul.c
	wcstoull.c
	wcswidth.c
	wcsxfrm.c
	wctob.c
	wcwidth.c
	wmemchr.c
	wmemcmp.c
	wmemcpy.c
	wmemmove.c
	wmemset.c
	wprintf.c
	wscanf.c
)

target_link_libraries(c-wchar PUBLIC
	c-stdio
	c-stdlib
	c-wctype
	libc-headers
)

set_target_properties(c-wchar PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}
)
