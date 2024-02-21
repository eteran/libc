cmake_minimum_required(VERSION 3.5)

add_library(c-all STATIC)

set_property(TARGET c-all PROPERTY ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

target_link_libraries(c-all PUBLIC
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

add_subdirectory(components)
add_subdirectory(crt)
add_subdirectory(sys)
