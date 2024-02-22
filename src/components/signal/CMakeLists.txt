cmake_minimum_required(VERSION 3.15)

set(SOURCE_FILES
	signal.c
	raise.c
)

add_library (c-signal STATIC ${SOURCE_FILES})

target_link_libraries(c-signal PUBLIC
	libc-headers
)

set_target_properties(c-signal PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}
	C_STANDARD 90
	C_STANDARD_REQUIRED TRUE
	C_EXTENSIONS OFF
)
