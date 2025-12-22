add_library(result INTERFACE
)

target_sources(result
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            include
        FILES
            include/result/Result.hpp
)

target_link_libraries(result
    PUBLIC
)

set_target_properties(result PROPERTIES FOLDER "modules/carrots_std/result")

# Tests
add_executable(result_tests
    tests/ResultTests.cpp
)

target_link_libraries(result_tests
    PRIVATE
        GTest::gtest_main
        result
)

include(GoogleTest)
gtest_discover_tests(result_tests)