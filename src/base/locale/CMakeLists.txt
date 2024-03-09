cmake_minimum_required(VERSION 3.15)

add_library (c-locale STATIC
	localeconv.c
	setlocale.c
)

target_link_libraries(c-locale PUBLIC
	libc-headers
)
set_target_properties(c-locale PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}
)
