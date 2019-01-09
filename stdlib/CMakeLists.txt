cmake_minimum_required(VERSION 3.0)

add_library (c-stdlib STATIC
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

target_include_directories (c-stdlib PUBLIC 
	${PROJECT_SOURCE_DIR}/include
	${PROJECT_SOURCE_DIR}/include/arch/${LIBC_ARCH}
)

target_link_libraries(c-stdlib LINK_PUBLIC 
	c-string
	c-stdio
	c-ctype
	c-signal
)

set_property(TARGET c-stdlib PROPERTY C_STANDARD 99)
set_property(TARGET c-stdlib PROPERTY ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

