cmake_minimum_required(VERSION 3.15)

add_library(c-all INTERFACE)

target_link_libraries(c-all INTERFACE
	c-base
	c-crt
	c-sys
)

add_subdirectory(base)
add_subdirectory(crt)
add_subdirectory(sys)
