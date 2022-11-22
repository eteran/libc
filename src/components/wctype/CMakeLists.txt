cmake_minimum_required(VERSION 3.5)

add_library(c-wctype STATIC
	wctype.c
)

target_link_libraries(c-wctype LINK_PUBLIC
	c-ctype
	c-wchar
	libc-headers
)

set_property(TARGET c-wctype PROPERTY ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
