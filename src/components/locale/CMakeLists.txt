cmake_minimum_required(VERSION 3.15)

set(SOURCE_FILES
	localeconv.c
	setlocale.c
)

add_library (c-locale STATIC ${SOURCE_FILES})

target_link_libraries(c-locale PUBLIC
	libc-headers
)
set_target_properties(c-locale PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}
	C_STANDARD 90
	C_STANDARD_REQUIRED TRUE
	C_EXTENSIONS OFF
)
