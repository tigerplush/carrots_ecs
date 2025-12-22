add_library(iterator STATIC
    src/StringIterator.cpp
)

target_sources(iterator
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            include
        FILES
            include/iterator/Enumerate.hpp
            include/iterator/Filter.hpp
            include/iterator/Iterator.hpp
            include/iterator/Split.hpp
            include/iterator/StringIterator.hpp
)

target_link_libraries(iterator
    PUBLIC
    option
)


# Tests
add_executable(iterator_tests
    tests/FilterTests.cpp
    tests/IteratorTests.cpp
    tests/StringIteratorTests.cpp
)

target_link_libraries(iterator_tests
    PRIVATE
        GTest::gtest_main
        iterator
)

include(GoogleTest)
gtest_discover_tests(iterator_tests)