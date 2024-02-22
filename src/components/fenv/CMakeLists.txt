cmake_minimum_required(VERSION 3.15)

add_library (c-fenv STATIC
	fegetexceptflag.c
	feholdexcept.c
	fesetexceptflag.c
	feupdateenv.c
)

target_link_libraries(c-fenv PUBLIC
	libc-headers
)

set_target_properties(c-fenv PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}
)
