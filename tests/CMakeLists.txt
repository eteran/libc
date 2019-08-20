cmake_minimum_required(VERSION 3.2)

add_executable(libc-test
	test.c
)

target_link_libraries(libc-test LINK_PUBLIC
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

target_compile_options(libc-test PRIVATE
)

set_property(TARGET libc-test PROPERTY C_STANDARD 99)
set_property(TARGET libc-test PROPERTY C_EXTENSIONS OFF)
set_property(TARGET libc-test PROPERTY RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

add_test(
	NAME libc-test
	COMMAND $<TARGET_FILE:libc-test>
)
