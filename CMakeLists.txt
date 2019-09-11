cmake_minimum_required(VERSION 3.0)
project(libstdc)

enable_testing()

set(CMAKE_C_FLAGS           "${CMAKE_C_FLAGS}   -pedantic -W -Wall -ffreestanding")
set(CMAKE_CXX_FLAGS         "${CMAKE_CXX_FLAGS} -pedantic -W -Wall -ffreestanding")
set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -nostdlib")

if(${CMAKE_SYSTEM_PROCESSOR} STREQUAL "x86_64")
	set(CMAKE_C_FLAGS           "${CMAKE_C_FLAGS} -m64")
	set(CMAKE_CXX_FLAGS         "${CMAKE_CXX_FLAGS} -m64")
	set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -m64")
	set(CMAKE_ASM_FLAGS         "${CMAKE_ASM_FLAGS} -m64")
	set(LIBC_ARCH               "x86_64")
elseif(${CMAKE_SYSTEM_PROCESSOR} MATCHES "i[3456]86")
	set(CMAKE_C_FLAGS           "${CMAKE_C_FLAGS} -m32")
	set(CMAKE_CXX_FLAGS         "${CMAKE_CXX_FLAGS} -m32")
	set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -m32")
	set(CMAKE_ASM_FLAGS         "${CMAKE_ASM_FLAGS} -m32")
	set(LIBC_ARCH               "i686")
endif()

add_definitions("-DENABLE_FPU")

add_subdirectory(include)
add_subdirectory(src)

option(LIBC_BUILD_TESTS "Enable Tests")

if(LIBC_BUILD_TESTS)
	add_subdirectory(tests)
endif()
