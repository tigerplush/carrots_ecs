add_library(entity STATIC
    src/Entity.cpp
)

target_sources(entity
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            include
        FILES
            include/entity/Entity.hpp
)

# Tests
add_executable(entity_tests
    tests/EntityTests.cpp
)

target_link_libraries(entity_tests
    PRIVATE
        GTest::gtest_main
        entity
)

include(GoogleTest)
gtest_discover_tests(entity_tests)