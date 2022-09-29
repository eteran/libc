cmake_minimum_required(VERSION 3.5)

enable_language(ASM)

add_library(c-crt STATIC
	_crt.c
	arch/${LIBC_ARCH}/_start.S
)

target_link_libraries(c-crt LINK_PUBLIC
	c-stdlib
	c-locale
	libc-headers
)

set_property(TARGET c-crt PROPERTY ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
