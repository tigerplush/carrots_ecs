add_library(iterator INTERFACE
)

target_sources(iterator
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            include
        FILES
            include/iterator/Iterator.hpp
)

target_link_libraries(iterator
    INTERFACE
)


# Tests
add_executable(iterator_tests
    tests/IteratorTests.cpp
)

target_link_libraries(iterator_tests
    PRIVATE
        GTest::gtest_main
        iterator
)

include(GoogleTest)
gtest_discover_tests(iterator_tests)