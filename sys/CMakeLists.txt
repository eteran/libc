cmake_minimum_required(VERSION 2.6)

set(CMAKE_C_FLAGS           "${CMAKE_C_FLAGS} -pedantic -W -Wall -ffreestanding")
set(CMAKE_CXX_FLAGS         "${CMAKE_CXX_FLAGS} -pedantic -W -Wall -ffreestanding")
set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -nostdlib")

set(SOURCE_FILES 
	heap.cc
	_support.cc
)

add_library (c-sys STATIC ${SOURCE_FILES})

target_include_directories (c-sys PUBLIC 
	${PROJECT_SOURCE_DIR}/include
	${PROJECT_SOURCE_DIR}/include/arch/x86_64
)

set_property(TARGET c-sys PROPERTY C_STANDARD 99)
set_property(TARGET c-sys PROPERTY CXX_STANDARD 11)
