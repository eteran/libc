cmake_minimum_required(VERSION 3.0)

enable_language(ASM)

add_library (c-setjmp STATIC
	arch/${LIBC_ARCH}/longjmp.S
	arch/${LIBC_ARCH}/setjmp.S	
)

target_include_directories (c-setjmp PUBLIC 
	${PROJECT_SOURCE_DIR}/include
	${PROJECT_SOURCE_DIR}/include/arch/${LIBC_ARCH}
)

target_link_libraries(c-setjmp LINK_PUBLIC 
	c-stdlib
	c-math
	c-string	
)

set_property(TARGET c-setjmp PROPERTY C_STANDARD 99)
set_property(TARGET c-setjmp PROPERTY ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
