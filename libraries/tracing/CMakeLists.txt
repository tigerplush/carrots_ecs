cmake_minimum_required(VERSION 3.23)

project(tracing VERSION 1.0.0 LANGUAGES CXX)

add_library(tracing INTERFACE
)

target_sources(tracing
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            include
        FILES
            include/DefaultLogSubscriber.hpp
            include/ILogSink.hpp
            include/ILogSubscriber.hpp
            include/Logger.hpp
            include/LogLevel.hpp
            include/LogLine.hpp
            include/StdCoutSink.hpp
            include/Tracing.hpp
)


# Tests
add_executable(tracing_tests
    tests/TracingTests.cpp
)

target_link_libraries(tracing_tests
    PRIVATE
        GTest::gtest_main
        tracing
)

include(GoogleTest)
gtest_discover_tests(tracing_tests)