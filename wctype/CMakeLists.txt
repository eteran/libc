cmake_minimum_required(VERSION 3.0)

add_library (c-wctype STATIC
	wctype.c
)

target_include_directories (c-wctype PUBLIC 
	${PROJECT_SOURCE_DIR}/include
	${PROJECT_SOURCE_DIR}/include/arch/${LIBC_ARCH}
)

target_link_libraries(c-wctype LINK_PUBLIC 
	c-ctype
)

set_property(TARGET c-wctype PROPERTY C_STANDARD 99)
set_property(TARGET c-wctype PROPERTY ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
