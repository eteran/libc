cmake_minimum_required(VERSION 3.15)

add_library(c-strings STATIC
	bcmp.c
	bcopy.c
	bzero.c
	ffs.c
	index.c
	rindex.c
	strcasecmp.c
	strncasecmp.c
)

target_link_libraries(c-strings PUBLIC
	c-string
	libc-headers
)

set_target_properties(c-strings PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}
)
