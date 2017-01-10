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

add_subdirectory(math)
add_subdirectory(string)
add_subdirectory(stdlib)
add_subdirectory(core)
add_subdirectory(crt)
add_subdirectory(time)
add_subdirectory(sys)

add_executable (libc-test test.c)
set_property(TARGET libc-test PROPERTY C_STANDARD 99)

target_link_libraries(libc-test LINK_PUBLIC 
	c-crt 
	c-math
	c-stdlib
	c-core 	
	c-string	
	c-sys
	c-time
)
