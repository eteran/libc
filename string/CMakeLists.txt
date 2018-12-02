cmake_minimum_required(VERSION 3.0)

add_library (c-string STATIC 
	memchr.c
	memcmp.c
	memcpy.c
	memmove.c
	memset.c
	strcat.c
	strchr.c
	strcmp.c
	strcoll.c
	strcpy.c
	strcspn.c
	strdup.c
	strerror.c
	strlcat.c
	strlcpy.c
	strlen.c
	strncat.c
	strncmp.c
	strncpy.c
	strndup.c
	strpbrk.c
	strrchr.c
	strspn.c
	strstr.c
	strtok.c
	strxfrm.c
)

target_include_directories (c-string PUBLIC 
	${PROJECT_SOURCE_DIR}/include
	${PROJECT_SOURCE_DIR}/include/arch/${LIBC_ARCH}
)

target_link_libraries(c-string LINK_PUBLIC 
	c-assert
)

set_property(TARGET c-string PROPERTY C_STANDARD 99)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR})
