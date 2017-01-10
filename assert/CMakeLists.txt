cmake_minimum_required(VERSION 2.6)

enable_language(ASM)

set(CMAKE_C_FLAGS           "${CMAKE_C_FLAGS} -pedantic -W -Wall -ffreestanding")
set(CMAKE_CXX_FLAGS         "${CMAKE_CXX_FLAGS} -pedantic -W -Wall -ffreestanding")
set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -nostdlib")

set(SOURCE_FILES
	assert.c
)

add_library (c-assert STATIC ${SOURCE_FILES})

target_include_directories (c-assert PUBLIC 
	${PROJECT_SOURCE_DIR}/include
)

if(${CMAKE_SYSTEM_PROCESSOR} STREQUAL "x86_64")
	target_include_directories (c-assert PUBLIC 
		${PROJECT_SOURCE_DIR}/include/arch/x86_64
	)
elseif(${CMAKE_SYSTEM_PROCESSOR} MATCHES "i[3456]86")
	target_include_directories (c-assert PUBLIC 
		${PROJECT_SOURCE_DIR}/include/arch/i686
	)
endif()

set_property(TARGET c-assert PROPERTY C_STANDARD 99)


target_link_libraries(c-assert LINK_PUBLIC 
	c-stdio
)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR})
