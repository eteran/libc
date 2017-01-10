cmake_minimum_required(VERSION 2.6)

enable_language(ASM)

set(CMAKE_C_FLAGS           "${CMAKE_C_FLAGS} -pedantic -W -Wall -ffreestanding")
set(CMAKE_CXX_FLAGS         "${CMAKE_CXX_FLAGS} -pedantic -W -Wall -ffreestanding")
set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -nostdlib")

set(SOURCE_FILES 
	bcmp.c
	bcopy.c
	bzero.c
	fegetexceptflag.c
	feholdexcept.c
	fesetexceptflag.c
	feupdateenv.c
	ffs.c
	imaxabs.c
	imaxdiv.c
	index.c
	localeconv.c
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
	wcstoimax.c
	wcstoumax.c
	wctype.c	
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
