cmake_minimum_required(VERSION 3.0)

add_library (c-sys STATIC
	heap.cpp
	heap.hpp
	syscall.hpp
	system.cpp
)

target_include_directories (c-sys PUBLIC 
	${PROJECT_SOURCE_DIR}/include
	${PROJECT_SOURCE_DIR}/include/arch/${LIBC_ARCH}
)

set_property(TARGET c-sys PROPERTY C_STANDARD 99)
set_property(TARGET c-sys PROPERTY CXX_STANDARD 11)
set_property(TARGET c-sys PROPERTY ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

target_link_libraries(c-sys LINK_PUBLIC 
	c-errno
	c-stdlib
)
