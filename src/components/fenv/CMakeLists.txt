cmake_minimum_required(VERSION 3.5)

add_library (c-fenv STATIC
	fegetexceptflag.c
	feholdexcept.c
	fesetexceptflag.c
	feupdateenv.c
)

target_link_libraries(c-fenv LINK_PUBLIC
	libc-headers
)

set_property(TARGET c-fenv PROPERTY ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
