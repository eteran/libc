cmake_minimum_required(VERSION 3.5)

enable_language(ASM)

add_library (c-setjmp STATIC
	arch/${LIBC_ARCH}/longjmp.S
	arch/${LIBC_ARCH}/setjmp.S
)

target_link_libraries(c-setjmp PUBLIC
	c-stdlib
	c-math
	c-string
	libc-headers
)

set_property(TARGET c-setjmp PROPERTY ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
