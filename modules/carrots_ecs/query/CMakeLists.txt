add_library(query INTERFACE
)

target_sources(query
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            include
        FILES
            include/query/Query.hpp
            include/query/QueryIterator.hpp
)

target_link_libraries(query
    INTERFACE
        world
        carrots_std
)


# Tests
add_executable(query_tests
    tests/QueryTests.cpp
)

target_link_libraries(query_tests
    PRIVATE
        GTest::gtest_main
        query
)

include(GoogleTest)
gtest_discover_tests(query_tests)