cmake_minimum_required(VERSION 3.2)

macro(CREATE_TEST NAME)
    add_executable(${NAME}-test ${NAME}-test.c)
    target_link_libraries(${NAME}-test LINK_PUBLIC
      c-all
    )

    target_compile_options(${NAME}-test
    PUBLIC
      -Wno-deprecated-declarations
    )

    set_target_properties(${NAME}-test
    PROPERTIES
        C_STANDARD 90
        C_EXTENSIONS OFF
    )

    add_test(
        NAME ${NAME}-test
        COMMAND $<TARGET_FILE:${NAME}-test>
    )
endmacro()

CREATE_TEST(all)
CREATE_TEST(assert)
# CREATE_TEST(assert-fail)
# set_tests_properties(assert-fail-test PROPERTIES WILL_FAIL TRUE)
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
CREATE_TEST(sys)
CREATE_TEST(time)
CREATE_TEST(trig)
CREATE_TEST(wchar)
CREATE_TEST(wctype)


