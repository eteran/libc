cmake_minimum_required(VERSION 3.15)

add_library (c-stdio STATIC
	stdio.c
	clearerr.c
	fclose.c
	feof.c
	ferror.c
	fflush.c
	fgetc.c
	fgetpos.c
	fgets.c
	fopen.c
	fprintf.c
	fputc.c
	fputs.c
	fread.c
	freopen.c
	fscanf.c
	fseek.c
	fsetpos.c
	ftell.c
	fwrite.c
	getchar.c
	gets.c
	perror.c
	printf.c
	putchar.c
	puts.c
	remove.c
	rename.c
	rewind.c
	scanf.c
	setbuf.c
	setvbuf.c
	snprintf.c
	sprintf.c
	sscanf.c
	tmpfile.c
	tmpnam.c
	ungetc.c
	vfprintf.c
	vfscanf.c
	vprintf.c
	vscanf.c
	vsnprintf.c
	vsprintf.c
	vsscanf.c
	_printf_engine.c
)

target_link_libraries(c-stdio PUBLIC
	c-stdlib
	c-math
	c-errno
	libc-headers
)

set_target_properties(c-stdio PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}
)
