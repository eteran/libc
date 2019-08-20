cmake_minimum_required(VERSION 3.0)

set(SOURCE_FILES
	localeconv.c
	setlocale.c
)

add_library (c-locale STATIC ${SOURCE_FILES})

target_link_libraries(c-locale LINK_PUBLIC 
	libc-headers
)
set_property(TARGET c-locale PROPERTY C_STANDARD 99)
set_property(TARGET c-locale PROPERTY ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
