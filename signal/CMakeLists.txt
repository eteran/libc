cmake_minimum_required(VERSION 3.0)

set(SOURCE_FILES
	signal.c
	raise.c
)

add_library (c-signal STATIC ${SOURCE_FILES})

target_include_directories (c-signal PUBLIC 
	${PROJECT_SOURCE_DIR}/include
	${PROJECT_SOURCE_DIR}/include/arch/${LIBC_ARCH}
)

target_link_libraries(c-signal LINK_PUBLIC 
)

set_property(TARGET c-signal PROPERTY C_STANDARD 99)
set_property(TARGET c-signal PROPERTY ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
