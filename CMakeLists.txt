cmake_minimum_required(VERSION 3.15)
project(libstdc)

enable_testing()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_compile_options(
	-pedantic
	-W
	-Wall
	-ffreestanding
	-Wno-long-long
	-Werror
)

if(${CMAKE_SYSTEM_PROCESSOR} STREQUAL "x86_64")
	set(LIBC_ARCH "x86_64")
elseif(${CMAKE_SYSTEM_PROCESSOR} MATCHES "i[3456]86")
	set(LIBC_ARCH "i686")
endif()

add_subdirectory(include)
add_subdirectory(src)

option(LIBC_BUILD_TESTS "Enable Tests")

if(LIBC_BUILD_TESTS)
	add_subdirectory(tests)
endif()
