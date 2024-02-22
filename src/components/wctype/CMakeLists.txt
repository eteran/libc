cmake_minimum_required(VERSION 3.15)

add_library(c-wctype STATIC
	wctype.c
)

target_link_libraries(c-wctype PUBLIC
	c-ctype
	c-wchar
	libc-headers
)

set_target_properties(c-wctype PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}
)
