cmake_minimum_required(VERSION 3.5)

macro(CREATE_TEST NAME)
  add_executable(${NAME}-test ${NAME}-test.c)
  target_link_libraries(${NAME}-test LINK_PUBLIC
    c-all
  )

  if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    target_link_libraries(${NAME}-test LINK_PUBLIC
      -lgcc
    )
  endif()

  target_compile_options(${NAME}-test
    PUBLIC
    -Wno-deprecated-declarations
  )

  set_target_properties(${NAME}-test
    PROPERTIES
    C_STANDARD 11
    C_EXTENSIONS OFF
  )

  add_test(
    NAME ${NAME}-test
    COMMAND $<TARGET_FILE:${NAME}-test>
  )
endmacro()

CREATE_TEST(all)
CREATE_TEST(assert)
CREATE_TEST(ctype)
CREATE_TEST(errno)
CREATE_TEST(fenv)
CREATE_TEST(inttypes)
CREATE_TEST(locale)
CREATE_TEST(math)
CREATE_TEST(setjmp)
CREATE_TEST(signal)
CREATE_TEST(stdio)
CREATE_TEST(stdlib)
CREATE_TEST(string)
CREATE_TEST(strings)
CREATE_TEST(time)
CREATE_TEST(wchar)
CREATE_TEST(wctype)
CREATE_TEST(complex)
CREATE_TEST(float)
CREATE_TEST(iso646)
CREATE_TEST(limits)
CREATE_TEST(stdalign)
CREATE_TEST(stdarg)
CREATE_TEST(stdatomic)
CREATE_TEST(stdbool)
CREATE_TEST(stddef)
CREATE_TEST(stdint)
CREATE_TEST(stdnoreturn)
CREATE_TEST(tgmath)
CREATE_TEST(threads)
CREATE_TEST(uchar)
