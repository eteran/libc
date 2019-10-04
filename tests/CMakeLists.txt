cmake_minimum_required(VERSION 3.2)

add_executable(libc-test test.c)
target_link_libraries(libc-test LINK_PUBLIC	c-all)
add_test(NAME libc-test COMMAND $<TARGET_FILE:libc-test>)

add_executable(qsort-test qsort-test.c)
target_link_libraries(qsort-test LINK_PUBLIC c-all)
add_test(NAME qsort-test COMMAND $<TARGET_FILE:qsort-test>)

add_executable(trig-test trig-test.c)
target_link_libraries(trig-test LINK_PUBLIC c-all)
add_test(NAME trig-test COMMAND $<TARGET_FILE:trig-test>)

set_target_properties(trig-test qsort-test libc-test
	PROPERTIES 
		C_STANDARD               ${LIBC_STANDARD}
		C_EXTENSIONS             OFF
		RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}
)
