cmake_minimum_required(VERSION 3.15)

add_library (c-signal STATIC
	signal.c
	raise.c
)

target_link_libraries(c-signal PUBLIC
	libc-headers
)

set_target_properties(c-signal PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}
)
