cmake_minimum_required(VERSION 2.6)
project(libstdc)

if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE "RelWithDebInfo" CACHE STRING "Choose the type of build, options are: Debug Release RelWithDebInfo MinSizeRel." FORCE)
endif()

set(CMAKE_C_FLAGS           "${CMAKE_C_FLAGS} -pedantic -W -Wall -ffreestanding")
set(CMAKE_CXX_FLAGS         "${CMAKE_CXX_FLAGS} -pedantic -W -Wall -ffreestanding")
set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -nostdlib")


if(${CMAKE_SYSTEM_PROCESSOR} STREQUAL "x86_64")
	set(CMAKE_C_FLAGS           "${CMAKE_C_FLAGS} -m64")
	set(CMAKE_CXX_FLAGS         "${CMAKE_CXX_FLAGS} -m64")
	set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -m64")
	set(CMAKE_ASM_FLAGS         "${CMAKE_ASM_FLAGS} -m64")
elseif(${CMAKE_SYSTEM_PROCESSOR} MATCHES "i[3456]86")
	set(CMAKE_C_FLAGS           "${CMAKE_C_FLAGS} -m32")
	set(CMAKE_CXX_FLAGS         "${CMAKE_CXX_FLAGS} -m32")
	set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -m32")
	set(CMAKE_ASM_FLAGS         "${CMAKE_ASM_FLAGS} -m32")
endif()


add_definitions("-DENABLE_FPU")

add_subdirectory(assert)
add_subdirectory(crt)
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
add_subdirectory(sys)
add_subdirectory(time)
add_subdirectory(wchar)
add_subdirectory(wctype)

add_executable (libc-test test.c)
set_property(TARGET libc-test PROPERTY C_STANDARD 99)

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

