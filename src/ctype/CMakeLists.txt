cmake_minimum_required(VERSION 3.0)

add_library (c-ctype STATIC 
	ctype.c
)

target_link_libraries(c-ctype LINK_PUBLIC 
	libc-headers
)

set_property(TARGET c-ctype PROPERTY ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
