add_library(world STATIC
    src/EntityMeta.cpp
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
        tracing
        archetype
        table
)

set_target_properties(world PROPERTIES FOLDER "modules/carrots_ecs/world")

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