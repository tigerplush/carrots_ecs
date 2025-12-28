add_library(carrots_std STATIC
    src/iterator/string_iterator.cpp
)

target_sources(carrots_std
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            include
        FILES
            include/carrots_std.hpp
            include/iterator/enumerate.hpp
            include/iterator/filter.hpp
            include/iterator/iterator.hpp
            include/iterator/split.hpp
            include/iterator/string_iterator.hpp
            include/option/option.hpp
            include/result/result.hpp
)

target_link_libraries(carrots_std
    PUBLIC
)

set_target_properties(carrots_std PROPERTIES FOLDER "modules/carrots_std")

# Tests
add_executable(carrots_std_tests
    tests/filter_tests.cpp
    tests/iterator_tests.cpp
    tests/option_tests.cpp
    tests/result_tests.cpp
    tests/string_iterator_tests.cpp
)

target_link_libraries(carrots_std_tests
    PRIVATE
        GTest::gtest_main
        carrots_std
)

include(GoogleTest)
gtest_discover_tests(carrots_std_tests)