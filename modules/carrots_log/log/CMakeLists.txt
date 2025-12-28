add_library(log INTERFACE
)

target_sources(log
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            include
        FILES
            include/log/Log.hpp
)

target_link_libraries(log
    PUBLIC
)

set_target_properties(log PROPERTIES FOLDER "modules/carrots_std/log")

# Tests
add_executable(log_tests
    tests/LogTests.cpp
)

target_link_libraries(log_tests
    PRIVATE
        GTest::gtest_main
        log
)

include(GoogleTest)
gtest_discover_tests(log_tests)