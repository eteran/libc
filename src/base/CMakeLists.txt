cmake_minimum_required(VERSION 3.15)

add_library(c-base INTERFACE)

target_link_libraries(c-base INTERFACE
	c-assert
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
	c-time
	c-wchar
	c-wctype
)

add_subdirectory(assert)
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
add_subdirectory(time)
add_subdirectory(wchar)
add_subdirectory(wctype)
