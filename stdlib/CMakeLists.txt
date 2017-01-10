cmake_minimum_required(VERSION 2.6)

enable_language(ASM)

set(CMAKE_C_FLAGS           "${CMAKE_C_FLAGS} -pedantic -W -Wall -ffreestanding")
set(CMAKE_CXX_FLAGS         "${CMAKE_CXX_FLAGS} -pedantic -W -Wall -ffreestanding")
set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -nostdlib")

set(SOURCE_FILES
	stdlib.c
	abort.c
	abs.c
	atexit.c
	atof.c
	atoi.c
	atol.c
	atoll.c
	bsearch.c
	calloc.c
	div.c
	exit.c
	_Exit.c
	free.c
	getenv.c
	labs.c
	ldiv.c
	llabs.c
	lldiv.c
	malloc.c
	mblen.c
	mbstowcs.c
	mbtowc.c
	qsort.c
	rand.c
	realloc.c
	srand.c
	strtod.c
	strtof.c
	strtol.c
	strtold.c
	strtoll.c
	strtoul.c
	strtoull.c
	system.c
	wcstombs.c
	wctomb.c
)

add_library (c-stdlib STATIC ${SOURCE_FILES})

target_include_directories (c-stdlib PUBLIC 
	${PROJECT_SOURCE_DIR}/include
)

if(${CMAKE_SYSTEM_PROCESSOR} STREQUAL "x86_64")
	target_include_directories (c-stdlib PUBLIC 
		${PROJECT_SOURCE_DIR}/include/arch/x86_64
	)
elseif(${CMAKE_SYSTEM_PROCESSOR} MATCHES "i[3456]86")
	target_include_directories (c-stdlib PUBLIC 
		${PROJECT_SOURCE_DIR}/include/arch/i686
	)
endif()

set_property(TARGET c-stdlib PROPERTY C_STANDARD 99)


target_link_libraries(c-stdlib LINK_PUBLIC 
	c-string
	c-stdio
	c-ctype
	c-signal
)

set_target_properties(c-stdlib
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
)
