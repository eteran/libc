cmake_minimum_required(VERSION 3.0)

add_library (c-inttypes STATIC 
	imaxabs.c
	imaxdiv.c
	strtoimax.c
	strtoumax.c
	wcstoimax.c
	wcstoumax.c
)

target_include_directories (c-inttypes PUBLIC 
	${PROJECT_SOURCE_DIR}/include
	${PROJECT_SOURCE_DIR}/include/arch/${LIBC_ARCH}
)

target_link_libraries(c-inttypes LINK_PUBLIC 
	c-stdlib
)
set_property(TARGET c-inttypes PROPERTY C_STANDARD 99)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR})
