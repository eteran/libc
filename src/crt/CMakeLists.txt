cmake_minimum_required(VERSION 3.15)

enable_language(ASM)

add_library(c-crt STATIC
	_crt.c
	arch/${LIBC_ARCH}/_start.S
)

target_link_libraries(c-crt PUBLIC
	c-stdlib
	c-locale
	libc-headers
)

set_target_properties(c-crt PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}
)
