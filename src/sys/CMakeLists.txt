cmake_minimum_required(VERSION 3.15)

add_library(c-sys STATIC
	heap.cpp
	heap.hpp
	syscall.hpp
	system.cpp
)

set_target_properties(c-sys
	PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}
	C_STANDARD 90
	C_STANDARD_REQUIRED TRUE
	C_EXTENSIONS OFF
	CXX_STANDARD 14
	CXX_STANDARD_REQUIRED TRUE
	CXX_EXTENSIONS OFF
)

target_link_libraries(c-sys PUBLIC
	c-errno
	c-stdlib
	libc-headers
)
