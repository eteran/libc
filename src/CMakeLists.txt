cmake_minimum_required(VERSION 3.0)

add_library(c-all STATIC)

set(LIBC_STANDARD 99)
set(CMAKE_C_FLAGS          "${CMAKE_C_FLAGS}   -Wno-long-long -Werror")
set(CMAKE_CXX_FLAGS        "${CMAKE_CXX_FLAGS} -Wno-long-long -Werror")


set_property(TARGET c-all PROPERTY ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

target_link_libraries(c-all LINK_PUBLIC 
	c-assert
	c-crt
	c-ctype
	c-errno
	c-fenv
	c-inttypes
	c-locale
	c-math
	c-setjmp
	c-signal
	c-stdio
	c-stdlib
	c-string
	c-strings
	c-sys
	c-time
	c-wchar
	c-wctype
)

add_subdirectory(assert)
add_subdirectory(crt)
add_subdirectory(ctype)
add_subdirectory(errno)
add_subdirectory(fenv)
add_subdirectory(inttypes)
add_subdirectory(locale)
add_subdirectory(math)
add_subdirectory(setjmp)
add_subdirectory(signal)
add_subdirectory(stdio)
add_subdirectory(stdlib)
add_subdirectory(string)
add_subdirectory(strings)
add_subdirectory(sys)
add_subdirectory(time)
add_subdirectory(wchar)
add_subdirectory(wctype)

