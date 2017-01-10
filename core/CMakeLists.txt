cmake_minimum_required(VERSION 2.6)

enable_language(ASM)

set(CMAKE_C_FLAGS           "${CMAKE_C_FLAGS} -pedantic -W -Wall -ffreestanding")
set(CMAKE_CXX_FLAGS         "${CMAKE_CXX_FLAGS} -pedantic -W -Wall -ffreestanding")
set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -nostdlib")

set(SOURCE_FILES 
	assert.c
	bcmp.c
	bcopy.c
	btowc.c
	bzero.c
	ctype.c
	errno.c
	fegetexceptflag.c
	feholdexcept.c
	fesetexceptflag.c
	feupdateenv.c
	ffs.c
	fgetwc.c
	fgetws.c
	fputwc.c
	fputws.c
	fwide.c
	fwprintf.c
	fwscanf.c
	getwchar.c
	imaxabs.c
	imaxdiv.c
	index.c
	localeconv.c
	mbrlen.c
	mbrtowc.c
	mbsinit.c
	mbsrtowcs.c
	putwchar.c
	raise.c
	rindex.c
	setlocale.c
	signal.c
	stdio.c
	stdlib.c
	strcasecmp.c
	strncasecmp.c
	strtoimax.c
	strtoumax.c
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
	wcstoimax.c
	wcstok.c
	wcstol.c
	wcstold.c
	wcstoll.c
	wcstoul.c
	wcstoull.c
	wcstoumax.c
	wcswidth.c
	wcsxfrm.c
	wctob.c
	wctype.c
	wcwidth.c
	wmemchr.c
	wmemcmp.c
	wmemcpy.c
	wmemmove.c
	wmemset.c
	wprintf.c
	wscanf.c
)

if(${CMAKE_SYSTEM_PROCESSOR} STREQUAL "x86_64")
	set(SOURCE_FILES ${SOURCE_FILES}
		arch/x86_64/longjmp.S
		arch/x86_64/setjmp.S			
	)
elseif(${CMAKE_SYSTEM_PROCESSOR} MATCHES "i[3456]86")
	set(SOURCE_FILES ${SOURCE_FILES}
		arch/i686/longjmp.S
		arch/i686/setjmp.S			
	)
endif()

add_library (c-core STATIC ${SOURCE_FILES})

target_include_directories (c-core PUBLIC 
	${PROJECT_SOURCE_DIR}/include
)

if(${CMAKE_SYSTEM_PROCESSOR} STREQUAL "x86_64")
	target_include_directories (c-core PUBLIC 
		${PROJECT_SOURCE_DIR}/include/arch/x86_64
	)
elseif(${CMAKE_SYSTEM_PROCESSOR} MATCHES "i[3456]86")
	target_include_directories (c-core PUBLIC 
		${PROJECT_SOURCE_DIR}/include/arch/i686
	)
endif()

set_property(TARGET c-core PROPERTY C_STANDARD 99)

target_link_libraries(c-core LINK_PUBLIC 
	c-stdlib
	c-math
	c-string	
)
