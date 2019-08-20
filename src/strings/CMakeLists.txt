cmake_minimum_required(VERSION 3.0)

add_library (c-strings STATIC
	bcmp.c
	bcopy.c
	bzero.c
	ffs.c
	index.c
	rindex.c
	strcasecmp.c
	strncasecmp.c
)

target_link_libraries(c-strings LINK_PUBLIC 
	libc-headers
)

set_property(TARGET c-strings PROPERTY C_STANDARD 99)
set_property(TARGET c-strings PROPERTY ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
