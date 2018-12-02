cmake_minimum_required(VERSION 2.6)

enable_language(ASM)

add_library (c-crt STATIC
	_crt.c
	arch/${LIBC_ARCH}/_start.S
)

target_include_directories (c-crt PUBLIC 
	${PROJECT_SOURCE_DIR}/include
	${PROJECT_SOURCE_DIR}/include/arch/${LIBC_ARCH}
)

target_link_libraries(c-crt LINK_PUBLIC 
	c-stdlib
	c-locale
)

set_property(TARGET c-crt PROPERTY C_STANDARD 99)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR})
