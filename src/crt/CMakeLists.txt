cmake_minimum_required(VERSION 3.15)

enable_language(ASM)

if(${CMAKE_SYSTEM_PROCESSOR} STREQUAL "x86_64")
	set(LIBC_ARCH "x86_64")
else()
	message(FATAL_ERROR "No Supported Architecture Detected")
endif()

add_library(c-crt STATIC
	_crt.c
	arch/${LIBC_ARCH}/_start.S
)

target_link_libraries(c-crt PUBLIC
	c-stdlib
	c-locale
	libc-headers
)

set_target_properties(c-crt PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}
)
