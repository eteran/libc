cmake_minimum_required(VERSION 3.15)

add_library(c-time STATIC
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

target_link_libraries(c-time PUBLIC
	c-stdio
	libc-headers
)

set_target_properties(c-time PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}
	C_STANDARD 90
	C_STANDARD_REQUIRED TRUE
	C_EXTENSIONS OFF
)
