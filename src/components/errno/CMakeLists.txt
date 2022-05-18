cmake_minimum_required(VERSION 3.0)

add_library (c-errno STATIC 
	errno.c
)

target_link_libraries(c-errno LINK_PUBLIC 
	libc-headers
)

set_property(TARGET c-errno PROPERTY ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
