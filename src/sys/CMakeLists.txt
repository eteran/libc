cmake_minimum_required(VERSION 3.5)

add_library(c-sys STATIC
	heap.cpp
	heap.hpp
	syscall.hpp
	system.cpp
)

set_target_properties(c-sys
	PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}
)

target_link_libraries(c-sys LINK_PUBLIC
	c-errno
	c-stdlib
	libc-headers
)
