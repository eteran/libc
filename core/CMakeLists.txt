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
	clearerr.c
	ctype.c
	errno.c
	fclose.c
	fegetexceptflag.c
	feholdexcept.c
	feof.c
	ferror.c
	fesetexceptflag.c
	feupdateenv.c
	fflush.c
	ffs.c
	fgetc.c
	fgetpos.c
	fgets.c
	fgetwc.c
	fgetws.c
	fopen.c
	fprintf.c
	fputc.c
	fputs.c
	fputwc.c
	fputws.c
	fread.c
	freopen.c
	fscanf.c
	fseek.c
	fsetpos.c
	ftell.c
	fwide.c
	fwprintf.c
	fwrite.c
	fwscanf.c
	getchar.c
	gets.c
	getwchar.c
	imaxabs.c
	imaxdiv.c
	index.c
	localeconv.c
	mbrlen.c
	mbrtowc.c
	mbsinit.c
	mbsrtowcs.c
	perror.c
	printf.c
	_printf_engine.c
	putchar.c
	puts.c
	putwchar.c
	raise.c
	remove.c
	rename.c
	rewind.c
	rindex.c
	scanf.c
	setbuf.c
	setlocale.c
	setvbuf.c
	signal.c
	snprintf.c
	sprintf.c
	sscanf.c
	stdio.c
	stdlib.c
	strcasecmp.c
	strncasecmp.c
	strtoimax.c
	strtoumax.c
	swprintf.c
	swscanf.c
	tmpfile.c
	tmpnam.c
	ungetc.c
	ungetwc.c
	vfprintf.c
	vfscanf.c
	vfwprintf.c
	vfwscanf.c
	vprintf.c
	vscanf.c
	vsnprintf.c
	vsprintf.c
	vsscanf.c
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
