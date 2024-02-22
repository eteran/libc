cmake_minimum_required(VERSION 3.15)

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

set_target_properties(c-setjmp PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}
	C_STANDARD 90
	C_STANDARD_REQUIRED TRUE
	C_EXTENSIONS OFF
)
