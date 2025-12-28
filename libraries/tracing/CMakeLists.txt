cmake_minimum_required(VERSION 3.23)

project(tracing VERSION 0.0.1 LANGUAGES CXX)

add_library(tracing INTERFACE
)

target_sources(tracing
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            include
            src
        FILES
            include/tracing.hpp
            src/default_log_subscriber.hpp
            src/log_level.hpp
            src/log_line.hpp
            src/logger.hpp
            src/logging_traits.hpp
            src/std_cout_sink.hpp
)


# Tests
add_executable(tracing_tests
    tests/tracing_tests.cpp
)

target_link_libraries(tracing_tests
    PRIVATE
        GTest::gtest_main
        tracing
)

include(GoogleTest)
gtest_discover_tests(tracing_tests)