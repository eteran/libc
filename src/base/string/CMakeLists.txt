cmake_minimum_required(VERSION 3.15)

add_library(c-string STATIC
	memchr.c
	memcmp.c
	memcpy.c
	memmove.c
	memset.c
	memswp.c
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

target_link_libraries(c-string PUBLIC
	c-assert
	libc-headers
)

set_target_properties(c-string PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}
)
