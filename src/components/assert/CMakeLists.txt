cmake_minimum_required(VERSION 3.15)

add_library(c-assert STATIC
	assert.c
)

set_target_properties(c-assert PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}
)

target_link_libraries(c-assert PUBLIC
	c-stdlib
	c-stdio
	libc-headers
)
