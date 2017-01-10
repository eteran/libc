cmake_minimum_required(VERSION 2.6)

enable_language(ASM)

set(CMAKE_C_FLAGS           "${CMAKE_C_FLAGS} -pedantic -W -Wall -ffreestanding")
set(CMAKE_CXX_FLAGS         "${CMAKE_CXX_FLAGS} -pedantic -W -Wall -ffreestanding")
set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -nostdlib")

set(SOURCE_FILES
	stdio.c
	clearerr.c
	fclose.c
	feof.c
	ferror.c
	fflush.c
	fgetc.c
	fgetpos.c
	fgets.c
	fopen.c
	fprintf.c
	fputc.c
	fputs.c
	fread.c
	freopen.c
	fscanf.c
	fseek.c
	fsetpos.c
	ftell.c
	fwrite.c
	getchar.c
	gets.c
	perror.c
	printf.c
	putchar.c
	puts.c
	remove.c
	rename.c
	rewind.c
	scanf.c
	setbuf.c
	setvbuf.c
	snprintf.c
	sprintf.c
	sscanf.c
	tmpfile.c
	tmpnam.c
	ungetc.c
	vfprintf.c
	vfscanf.c
	vprintf.c
	vscanf.c
	vsnprintf.c
	vsprintf.c
	vsscanf.c
	_printf_engine.c
)

add_library (c-stdio STATIC ${SOURCE_FILES})

target_include_directories (c-stdio PUBLIC 
	${PROJECT_SOURCE_DIR}/include
)

if(${CMAKE_SYSTEM_PROCESSOR} STREQUAL "x86_64")
	target_include_directories (c-stdio PUBLIC 
		${PROJECT_SOURCE_DIR}/include/arch/x86_64
	)
elseif(${CMAKE_SYSTEM_PROCESSOR} MATCHES "i[3456]86")
	target_include_directories (c-stdio PUBLIC 
		${PROJECT_SOURCE_DIR}/include/arch/i686
	)
endif()

set_property(TARGET c-stdio PROPERTY C_STANDARD 99)


target_link_libraries(c-stdio LINK_PUBLIC 
	c-stdlib
)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR})
