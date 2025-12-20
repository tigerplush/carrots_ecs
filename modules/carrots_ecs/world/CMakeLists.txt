add_library(world STATIC
    src/World.cpp
)

target_sources(world
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            include
        FILES
            include/world/World.hpp
)

target_link_libraries(world
    PUBLIC
        archetype
        table
)


# Tests
add_executable(world_tests
    tests/WorldTests.cpp
)

target_link_libraries(world_tests
    PRIVATE
        GTest::gtest_main
        world
)

include(GoogleTest)
gtest_discover_tests(world_tests)