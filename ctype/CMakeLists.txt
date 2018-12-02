cmake_minimum_required(VERSION 2.6)

add_library (c-ctype STATIC 
	ctype.c
)

target_include_directories (c-ctype PUBLIC 
	${PROJECT_SOURCE_DIR}/include
	${PROJECT_SOURCE_DIR}/include/arch/${LIBC_ARCH}
)

set_property(TARGET c-ctype PROPERTY C_STANDARD 99)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR})
