cmake_minimum_required(VERSION 3.15)

add_library(c-inttypes STATIC
	imaxabs.c
	imaxdiv.c
	strtoimax.c
	strtoumax.c
	wcstoimax.c
	wcstoumax.c
)

target_link_libraries(c-inttypes PUBLIC
	c-stdlib
	libc-headers
)
set_target_properties(c-inttypes PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}
)
