cmake_minimum_required(VERSION 3.0)

set(SOURCE_FILES
	localeconv.c
	setlocale.c
)

add_library (c-locale STATIC ${SOURCE_FILES})

target_include_directories (c-locale PUBLIC 
	${PROJECT_SOURCE_DIR}/include
	${PROJECT_SOURCE_DIR}/include/arch/${LIBC_ARCH}
)

set_property(TARGET c-locale PROPERTY C_STANDARD 99)
set_property(TARGET c-locale PROPERTY ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
