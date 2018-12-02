cmake_minimum_required(VERSION 3.0)

add_library (c-assert STATIC 
	assert.c
)

target_include_directories (c-assert PUBLIC 
	${PROJECT_SOURCE_DIR}/include
	${PROJECT_SOURCE_DIR}/include/arch/${LIBC_ARCH}
)

set_property(TARGET c-assert PROPERTY C_STANDARD 99)

target_link_libraries(c-assert LINK_PUBLIC 
	c-stdlib
	c-stdio
)

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR})
