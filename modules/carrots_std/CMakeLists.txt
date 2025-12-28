add_subdirectory(iterator)
add_subdirectory(option)

add_library(carrots_std INTERFACE)

target_sources(carrots_std
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            include
        FILES
            include/CarrotsStd.hpp
            include/result/result.hpp
)

target_link_libraries(carrots_std
    INTERFACE
        iterator
        option
)

set_target_properties(carrots_std PROPERTIES FOLDER "modules/carrots_std")

# Tests
add_executable(carrots_std_tests
    tests/result_tests.cpp
)

target_link_libraries(carrots_std_tests
    PRIVATE
        GTest::gtest_main
        carrots_std
)

include(GoogleTest)
gtest_discover_tests(carrots_std_tests)