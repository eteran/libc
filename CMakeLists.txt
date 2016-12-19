cmake_minimum_required(VERSION 2.6)
project(libstdc)

set(CMAKE_C_FLAGS           "${CMAKE_C_FLAGS} -pedantic -W -Wall -ffreestanding")
set(CMAKE_CXX_FLAGS         "${CMAKE_CXX_FLAGS} -pedantic -W -Wall -ffreestanding")
set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -nostdlib")

add_definitions("-DENABLE_FPU")

add_subdirectory(math)
add_subdirectory(core)
add_subdirectory(crt)
add_subdirectory(sys)

add_executable (libc-test test.c)
set_property(TARGET libc-test PROPERTY C_STANDARD 99)

target_link_libraries(libc-test LINK_PUBLIC 
	Crt 
	Core 
	Math
	Sys
)
