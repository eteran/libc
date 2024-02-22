cmake_minimum_required(VERSION 3.15)

add_library (c-errno STATIC
	errno.c
)

target_link_libraries(c-errno PUBLIC
	libc-headers
)

set_target_properties(c-errno PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}
	C_STANDARD 90
	C_STANDARD_REQUIRED TRUE
	C_EXTENSIONS OFF
)
