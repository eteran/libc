cmake_minimum_required(VERSION 3.0)

add_library (c-ctype STATIC 
	ctype.c
)

target_include_directories (c-ctype PUBLIC 
	${PROJECT_SOURCE_DIR}/include
	${PROJECT_SOURCE_DIR}/include/arch/${LIBC_ARCH}
)

set_property(TARGET c-ctype PROPERTY C_STANDARD 99)
set_property(TARGET c-ctype PROPERTY ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
