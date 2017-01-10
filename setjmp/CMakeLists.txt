cmake_minimum_required(VERSION 2.6)

enable_language(ASM)

set(CMAKE_C_FLAGS           "${CMAKE_C_FLAGS} -pedantic -W -Wall -ffreestanding")
set(CMAKE_CXX_FLAGS         "${CMAKE_CXX_FLAGS} -pedantic -W -Wall -ffreestanding")
set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -nostdlib")

set(SOURCE_FILES 
)

if(${CMAKE_SYSTEM_PROCESSOR} STREQUAL "x86_64")
	set(SOURCE_FILES ${SOURCE_FILES}
		arch/x86_64/longjmp.S
		arch/x86_64/setjmp.S			
	)
elseif(${CMAKE_SYSTEM_PROCESSOR} MATCHES "i[3456]86")
	set(SOURCE_FILES ${SOURCE_FILES}
		arch/i686/longjmp.S
		arch/i686/setjmp.S			
	)
endif()

add_library (c-setjmp STATIC ${SOURCE_FILES})

target_include_directories (c-setjmp PUBLIC 
	${PROJECT_SOURCE_DIR}/include
)

if(${CMAKE_SYSTEM_PROCESSOR} STREQUAL "x86_64")
	target_include_directories (c-setjmp PUBLIC 
		${PROJECT_SOURCE_DIR}/include/arch/x86_64
	)
elseif(${CMAKE_SYSTEM_PROCESSOR} MATCHES "i[3456]86")
	target_include_directories (c-setjmp PUBLIC 
		${PROJECT_SOURCE_DIR}/include/arch/i686
	)
endif()

set_property(TARGET c-setjmp PROPERTY C_STANDARD 99)

target_link_libraries(c-setjmp LINK_PUBLIC 
	c-stdlib
	c-math
	c-string	
)

set_target_properties(c-setjmp
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
)
