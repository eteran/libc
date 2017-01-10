cmake_minimum_required(VERSION 2.6)

enable_language(ASM)

set(CMAKE_C_FLAGS           "${CMAKE_C_FLAGS} -pedantic -W -Wall -ffreestanding")
set(CMAKE_CXX_FLAGS         "${CMAKE_CXX_FLAGS} -pedantic -W -Wall -ffreestanding")
set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -nostdlib")

set(SOURCE_FILES
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

add_library (c-wchar STATIC ${SOURCE_FILES})

target_include_directories (c-wchar PUBLIC 
	${PROJECT_SOURCE_DIR}/include
)

if(${CMAKE_SYSTEM_PROCESSOR} STREQUAL "x86_64")
	target_include_directories (c-wchar PUBLIC 
		${PROJECT_SOURCE_DIR}/include/arch/x86_64
	)
elseif(${CMAKE_SYSTEM_PROCESSOR} MATCHES "i[3456]86")
	target_include_directories (c-wchar PUBLIC 
		${PROJECT_SOURCE_DIR}/include/arch/i686
	)
endif()

set_property(TARGET c-wchar PROPERTY C_STANDARD 99)


target_link_libraries(c-wchar LINK_PUBLIC 

)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR})
