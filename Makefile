
SHELL=/bin/sh

AS      := $(CC)
LD      := $(CC)
MKDIR   := mkdir -p
OBJ_DIR := .obj

.SUFFIXES:

$(OBJ_DIR)/%.o: %.cc
	$(CXX) $(CXXFLAGS) -MMD -c $< -o $@

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -MMD -c $< -o $@

$(OBJ_DIR)/%.o: %.S
	$(AS) $(AFLAGS) -MMD -c $< -o $@
	
VPATH := src src/math src/arch/x86_64 

TARGET = libc.a

# -Wsuggest-attribute=pure -Wsuggest-attribute=const -Wsuggest-attribute=noreturn -Wsuggest-attribute=format
# -Wstrict-overflow=2

CXXFLAGS  := -DENABLE_FPU -std=c++03 -pedantic -Wextra -Wall -Iinclude -ffreestanding -march=native -O2 -g3 -Iinclude/arch/x86_64 -Wno-long-long -Wold-style-cast -fno-rtti -fno-exceptions
CFLAGS    := -DENABLE_FPU -std=c99   -pedantic -Wextra -Wall -Iinclude -ffreestanding -march=native -O2 -g3 -Iinclude/arch/x86_64 -Wno-long-long
AFLAGS    := -Iinclude/arch/x86_64
LDFLAGS   := -static -nostdlib #-nodefaultlibs -nostartfiles

H_FILES := \
	include/assert.h      \
	include/complex.h     \
	include/ctype.h       \
	include/errno.h       \
	include/fenv.h        \
	include/float.h       \
	include/inttypes.h    \
	include/iso646.h      \
	include/limits.h      \
	include/locale.h      \
	include/math.h        \
	include/setjmp.h      \
	include/signal.h      \
	include/stdalign.h    \
	include/stdarg.h      \
	include/stdatomic.h   \
	include/stdbool.h     \
	include/stddef.h      \
	include/stdint.h      \
	include/stdio.h       \
	include/stdlib.h      \
	include/stdnoreturn.h \
	include/string.h      \
	include/strings.h     \
	include/tgmath.h      \
	include/threads.h     \
	include/time.h        \
	include/uchar.h       \
	include/wchar.h       \
	include/wctype.h      \

S_FILES := \
	_start.S          \
	setjmp.S          \
	longjmp.S         \

	
CXX_FILES := \
	_support.cc       \
	heap.cc           \
	
C_FILES := \
	_Exit.c \
	_crt.c \
	_printf_engine.c \
	abort.c \
	abs.c \
	asctime.c \
	assert.c \
	atexit.c \
	atof.c \
	atoi.c \
	atol.c \
	atoll.c \
	bcmp.c \
	bcopy.c \
	bsearch.c \
	btowc.c \
	bzero.c \
	calloc.c \
	clearerr.c \
	clock.c \
	ctime.c \
	ctype.c \
	difftime.c \
	div.c \
	errno.c \
	exit.c \
	fclose.c \
	fegetexceptflag.c \
	feholdexcept.c \
	feof.c \
	ferror.c \
	fesetexceptflag.c \
	feupdateenv.c \
	fflush.c \
	ffs.c \
	fgetc.c \
	fgetpos.c \
	fgets.c \
	fgetwc.c \
	fgetws.c \
	fopen.c \
	fprintf.c \
	fputc.c \
	fputs.c \
	fputwc.c \
	fputws.c \
	fread.c \
	free.c \
	freopen.c \
	fscanf.c \
	fseek.c \
	fsetpos.c \
	ftell.c \
	fwide.c \
	fwprintf.c \
	fwrite.c \
	fwscanf.c \
	getchar.c \
	getenv.c \
	gets.c \
	getwchar.c \
	gmtime.c \
	imaxabs.c \
	imaxdiv.c \
	index.c \
	labs.c \
	ldiv.c \
	llabs.c \
	lldiv.c \
	localeconv.c \
	localtime.c \
	malloc.c \
	mblen.c \
	mbrlen.c \
	mbrtowc.c \
	mbsinit.c \
	mbsrtowcs.c \
	mbstowcs.c \
	mbtowc.c \
	memchr.c \
	memcmp.c \
	memcpy.c \
	memmove.c \
	memset.c \
	mktime.c \
	perror.c \
	printf.c \
	putchar.c \
	puts.c \
	putwchar.c \
	qsort.c \
	raise.c \
	rand.c \
	realloc.c \
	remove.c \
	rename.c \
	rewind.c \
	rindex.c \
	scanf.c \
	setbuf.c \
	setlocale.c \
	setvbuf.c \
	signal.c \
	snprintf.c \
	sprintf.c \
	srand.c \
	sscanf.c \
	stdio.c \
	stdlib.c \
	strcasecmp.c \
	strcat.c \
	strchr.c \
	strcmp.c \
	strcoll.c \
	strcpy.c \
	strcspn.c \
	strdup.c \
	strerror.c \
	strftime.c \
	strlcat.c \
	strlcpy.c \
	strlen.c \
	strncasecmp.c \
	strncat.c \
	strncmp.c \
	strncpy.c \
	strndup.c \
	strpbrk.c \
	strrchr.c \
	strspn.c \
	strstr.c \
	strtod.c \
	strtof.c \
	strtoimax.c \
	strtok.c \
	strtol.c \
	strtold.c \
	strtoll.c \
	strtoul.c \
	strtoull.c \
	strtoumax.c \
	strxfrm.c \
	swprintf.c \
	swscanf.c \
	system.c \
	time.c \
	tmpfile.c \
	tmpnam.c \
	ungetc.c \
	ungetwc.c \
	vfprintf.c \
	vfscanf.c \
	vfwprintf.c \
	vfwscanf.c \
	vprintf.c \
	vscanf.c \
	vsnprintf.c \
	vsprintf.c \
	vsscanf.c \
	vswprintf.c \
	vswscanf.c \
	vwprintf.c \
	vwscanf.c \
	wcrtomb.c \
	wcscat.c \
	wcschr.c \
	wcscmp.c \
	wcscoll.c \
	wcscpy.c \
	wcscspn.c \
	wcsftime.c \
	wcslen.c \
	wcsncat.c \
	wcsncmp.c \
	wcsncpy.c \
	wcspbrk.c \
	wcsrchr.c \
	wcsrtombs.c \
	wcsspn.c \
	wcsstr.c \
	wcstod.c \
	wcstof.c \
	wcstoimax.c \
	wcstok.c \
	wcstol.c \
	wcstold.c \
	wcstoll.c \
	wcstombs.c \
	wcstoul.c \
	wcstoull.c \
	wcstoumax.c \
	wcswidth.c \
	wcsxfrm.c \
	wctob.c \
	wctomb.c \
	wctype.c \
	wcwidth.c \
	wmemchr.c \
	wmemcmp.c \
	wmemcpy.c \
	wmemmove.c \
	wmemset.c \
	wprintf.c \
	wscanf.c \
	sqrt.c \
	atan.c \
	floor.c \
	trunc.c \
	ceil.c \
	sin.c \
	atan2.c \
	fabs.c \
	round.c \
	log.c \
	fmod.c \
	copysign.c \
	log10.c \
	fenv.c \
	acos.c \
	acosf.c \
	acosh.c \
	acoshf.c \
	acoshl.c \
	acosl.c \
	asin.c \
	asinf.c \
	asinh.c \
	asinhf.c \
	asinhl.c \
	asinl.c \
	atan2f.c \
	atan2l.c \
	atanf.c \
	atanh.c \
	atanhf.c \
	atanhl.c \
	atanl.c \
	cbrt.c \
	cbrtf.c \
	cbrtl.c \
	ceilf.c \
	ceill.c \
	copysignf.c \
	copysignl.c \
	cos.c \
	cosf.c \
	cosh.c \
	coshf.c \
	coshl.c \
	cosl.c \
	erf.c \
	erfc.c \
	erfcf.c \
	erfcl.c \
	erff.c \
	erfl.c \
	exp.c \
	exp2.c \
	exp2f.c \
	exp2l.c \
	expf.c \
	expl.c \
	expm1.c \
	expm1f.c \
	expm1l.c \
	fabsf.c \
	fabsl.c \
	fdim.c \
	fdimf.c \
	fdiml.c \
	floorf.c \
	floorl.c \
	fma.c \
	fmaf.c \
	fmal.c \
	fmax.c \
	fmaxf.c \
	fmaxl.c \
	fmin.c \
	fminf.c \
	fminl.c \
	fmodf.c \
	fmodl.c \
	frexp.c \
	frexpf.c \
	frexpl.c \
	hypot.c \
	hypotf.c \
	hypotl.c \
	ilogb.c \
	ilogbf.c \
	ilogbl.c \
	ldexp.c \
	ldexpf.c \
	ldexpl.c \
	lgamma.c \
	lgammaf.c \
	lgammal.c \
	llrint.c \
	llrintf.c \
	llrintl.c \
	llround.c \
	llroundf.c \
	llroundl.c \
	log10f.c \
	log10l.c \
	log1p.c \
	log1pf.c \
	log1pl.c \
	log2.c \
	log2f.c \
	log2l.c \
	logb.c \
	logbf.c \
	logbl.c \
	logf.c \
	logl.c \
	lrint.c \
	lrintf.c \
	lrintl.c \
	lround.c \
	lroundf.c \
	lroundl.c \
	modf.c \
	modff.c \
	modfl.c \
	nan.c \
	nanf.c \
	nanl.c \
	nearbyint.c \
	nearbyintf.c \
	nearbyintl.c \
	nextafter.c \
	nextafterf.c \
	nextafterl.c \
	nexttoward.c \
	nexttowardf.c \
	nexttowardl.c \
	pow.c \
	powf.c \
	powl.c \
	remainder.c \
	remainderf.c \
	remainderl.c \
	remquo.c \
	remquof.c \
	remquol.c \
	rint.c \
	rintf.c \
	rintl.c \
	roundf.c \
	roundl.c \
	scalbln.c \
	scalblnf.c \
	scalblnl.c \
	scalbn.c \
	scalbnf.c \
	scalbnl.c \
	sinf.c \
	sinh.c \
	sinhf.c \
	sinhl.c \
	sinl.c \
	sqrtf.c \
	sqrtl.c \
	tan.c \
	tanf.c \
	tanh.c \
	tanhf.c \
	tanhl.c \
	tanl.c \
	tgamma.c \
	tgammaf.c \
	tgammal.c \
	truncf.c \
	truncl.c \ 



O_FILES := $(patsubst %.cc, $(OBJ_DIR)/%.o, $(CXX_FILES)) $(patsubst %.c, $(OBJ_DIR)/%.o, $(C_FILES)) $(patsubst %.S, $(OBJ_DIR)/%.o, $(S_FILES))
D_FILES := $(O_FILES:.o=.d)

SOURCEFILES :=	$(H_FILES) $(CXX_FILES) $(C_FILES) $(S_FILES)
.PRECIOUS:	$(SOURCEFILES)
.PHONY:     all clean

all: $(TARGET) libc-test

$(O_FILES): | $(OBJ_DIR) 

$(D_FILES): | $(OBJ_DIR)

$(OBJ_DIR) :
	@$(MKDIR) $@

$(TARGET): $(O_FILES) 
	$(AR) rcs $@ $^
	
libc-test: $(OBJ_DIR)/test.o $(OBJ_DIR)/_crt.o $(TARGET)
	$(LD) $^ $(LDFLAGS) -o $@

clean:
	$(RM) $(O_FILES) $(D_FILES) $(TARGET) $(OBJ_DIR)/test.o $(OBJ_DIR)/test.d $(OBJ_DIR)/_crt.o libc-test

-include $(D_FILES)

