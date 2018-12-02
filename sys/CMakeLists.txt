cmake_minimum_required(VERSION 3.0)

add_library (c-sys STATIC
	heap.cc
	_support.cc
)

target_include_directories (c-sys PUBLIC 
	${PROJECT_SOURCE_DIR}/include
	${PROJECT_SOURCE_DIR}/include/arch/${LIBC_ARCH}
)

set_property(TARGET c-sys PROPERTY C_STANDARD 99)
set_property(TARGET c-sys PROPERTY CXX_STANDARD 11)


target_link_libraries(c-sys LINK_PUBLIC 
	c-errno
	c-stdlib
)

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR})
