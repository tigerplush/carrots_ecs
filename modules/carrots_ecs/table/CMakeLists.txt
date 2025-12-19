add_library(table STATIC
    src/ColumnId.cpp
    src/Table.cpp
    src/TableRow.cpp
)

target_sources(table
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            include
        FILES
            include/Table.hpp
)

target_link_libraries(table
    PUBLIC
        component
        entity
)


# Tests
add_executable(table_tests
    tests/TableTests.cpp
)

target_link_libraries(table_tests
    PRIVATE
        GTest::gtest_main
        table
)

include(GoogleTest)
gtest_discover_tests(table_tests)