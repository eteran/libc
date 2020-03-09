cmake_minimum_required(VERSION 3.0)
project(libstdc)

enable_testing()

set(CMAKE_C_STANDARD   99)
set(CMAKE_C_EXTENSIONS OFF)

add_compile_options(-pedantic -W -Wall -ffreestanding -Wno-long-long -Werror)
add_link_options(-nostdlib)

if(${CMAKE_SYSTEM_PROCESSOR} STREQUAL "x86_64")
	add_compile_options(-m64)
	add_link_options(-m64)
	set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -m64")
	set(LIBC_ARCH "x86_64")
elseif(${CMAKE_SYSTEM_PROCESSOR} MATCHES "i[3456]86")
	add_compile_options(-m32)
	add_link_options(-m32)
	set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -m32")
	set(LIBC_ARCH "i686")
endif()

add_subdirectory(include)
add_subdirectory(src)

option(LIBC_BUILD_TESTS "Enable Tests")
if(LIBC_BUILD_TESTS)
	add_subdirectory(tests)
endif()
