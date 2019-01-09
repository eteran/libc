cmake_minimum_required(VERSION 3.0)

add_library (c-fenv STATIC
	fegetexceptflag.c
	feholdexcept.c
	fesetexceptflag.c
	feupdateenv.c
)

target_include_directories (c-fenv PUBLIC 
	${PROJECT_SOURCE_DIR}/include
	${PROJECT_SOURCE_DIR}/include/arch/${LIBC_ARCH}
)

set_property(TARGET c-fenv PROPERTY C_STANDARD 99)
set_property(TARGET c-fenv PROPERTY ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
