cmake_minimum_required(VERSION 3.15)

add_library(c-stdlib STATIC
	_Exit.c
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
	stdlib.c
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

target_link_libraries(c-stdlib PUBLIC
	c-ctype
	c-signal
	c-stdio
	c-string
	c-strings
	c-wchar
	libc-headers
)

set_target_properties(c-stdlib PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}
)
