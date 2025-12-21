add_library(option STATIC
    src/Option.cpp
)

target_sources(option
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            include
        FILES
            include/option/Option.hpp
)

target_link_libraries(option
    PUBLIC
)


# Tests
add_executable(option_tests
    tests/OptionTests.cpp
)

target_link_libraries(option_tests
    PRIVATE
        GTest::gtest_main
        option
)

include(GoogleTest)
gtest_discover_tests(option_tests)