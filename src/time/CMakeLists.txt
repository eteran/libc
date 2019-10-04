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

target_link_libraries(c-time LINK_PUBLIC 
	c-stdio
	libc-headers
)

set_property(TARGET c-time PROPERTY C_STANDARD ${LIBC_STANDARD})
set_property(TARGET c-time PROPERTY ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
