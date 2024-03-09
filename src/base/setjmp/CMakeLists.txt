cmake_minimum_required(VERSION 3.15)

enable_language(ASM)

if(${CMAKE_SYSTEM_PROCESSOR} STREQUAL "x86_64")
	set(LIBC_ARCH "x86_64")
elseif(${CMAKE_SYSTEM_PROCESSOR} MATCHES "i[3456]86")
	set(LIBC_ARCH "i686")
endif()

add_library (c-setjmp STATIC
	arch/${LIBC_ARCH}/longjmp.S
	arch/${LIBC_ARCH}/setjmp.S
)

target_link_libraries(c-setjmp PUBLIC
	c-stdlib
	c-math
	c-string
	libc-headers
)

set_target_properties(c-setjmp PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}
)
