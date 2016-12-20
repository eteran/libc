cmake_minimum_required(VERSION 2.6)

enable_language(ASM)

set(CMAKE_C_FLAGS           "${CMAKE_C_FLAGS} -pedantic -W -Wall -ffreestanding")
set(CMAKE_CXX_FLAGS         "${CMAKE_CXX_FLAGS} -pedantic -W -Wall -ffreestanding")
set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -nostdlib")

set(SOURCE_FILES
	_crt.c
	arch/x86_64/_start.S
)

add_library (c-crt STATIC ${SOURCE_FILES})

target_include_directories (c-crt PUBLIC 
	${PROJECT_SOURCE_DIR}/include
	${PROJECT_SOURCE_DIR}/include/arch/x86_64
)

set_property(TARGET c-crt PROPERTY C_STANDARD 99)
