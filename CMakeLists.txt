cmake_minimum_required(VERSION 3.15)
project(libstdc)

enable_testing()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_compile_options(
	-pedantic
	-W
	-Wall
	-ffreestanding
	-Wno-long-long
	-Werror
)

add_subdirectory(include)
add_subdirectory(src)

option(LIBC_BUILD_TESTS "Enable Tests")

if(LIBC_BUILD_TESTS)
	add_subdirectory(tests)
endif()
