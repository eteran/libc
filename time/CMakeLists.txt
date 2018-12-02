cmake_minimum_required(VERSION 3.0)

add_library (c-time STATIC 
	asctime.c
	clock.c
	ctime.c
	difftime.c
	gmtime.c
	localtime.c
	mktime.c
	strftime.c
	time.c
)

target_include_directories (c-time PUBLIC 
	${PROJECT_SOURCE_DIR}/include
	${PROJECT_SOURCE_DIR}/include/arch/${LIBC_ARCH}
)

target_link_libraries(c-time LINK_PUBLIC 
	c-stdio
)
set_property(TARGET c-time PROPERTY C_STANDARD 99)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR})
