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

target_include_directories (c-strings PUBLIC 
	${PROJECT_SOURCE_DIR}/include
	${PROJECT_SOURCE_DIR}/include/arch/${LIBC_ARCH}
)

set_property(TARGET c-strings PROPERTY C_STANDARD 99)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR})
