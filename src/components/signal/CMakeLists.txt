cmake_minimum_required(VERSION 3.0)

set(SOURCE_FILES
	signal.c
	raise.c
)

add_library (c-signal STATIC ${SOURCE_FILES})

target_link_libraries(c-signal LINK_PUBLIC 
	libc-headers
)

set_property(TARGET c-signal PROPERTY ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
