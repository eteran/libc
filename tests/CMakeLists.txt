cmake_minimum_required(VERSION 3.2)

add_executable(libc-test
	test.c
)

target_link_libraries(libc-test LINK_PUBLIC
	c-all
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



add_executable(qsort-test
	qsort_test.c
)

target_link_libraries(qsort-test LINK_PUBLIC
	c-all
)

target_compile_options(qsort-test PRIVATE
)

set_property(TARGET qsort-test PROPERTY C_STANDARD 99)
set_property(TARGET qsort-test PROPERTY C_EXTENSIONS OFF)
set_property(TARGET qsort-test PROPERTY RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

add_test(
	NAME qsort-test
	COMMAND $<TARGET_FILE:qsort-test>
)
