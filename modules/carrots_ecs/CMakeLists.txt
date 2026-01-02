cmake_minimum_required(VERSION 3.23)

project(carrots_ecs VERSION 0.0.1 LANGUAGES CXX)

add_library(carrots_ecs STATIC
    src/archetype/archetype.cpp
    src/component/component_id.cpp
    src/entity/entity.cpp
    src/table/column_id.cpp
    src/table/table_id.cpp
    src/table/table_row.cpp
    src/table/table.cpp
    src/world/entity_meta.cpp
    src/world/world.cpp
)

target_sources(carrots_ecs
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            include
        FILES
            include/carrots_ecs.hpp
            include/archetype/archetype_hasher.hpp
            include/archetype/archetype.hpp
            include/component/component_id.hpp
            include/entity/entity.hpp
            include/query/components.hpp
            include/query/filters.hpp
            include/query/query_iterator.hpp
            include/query/query_traits.hpp
            include/query/query.hpp
            include/schedule/schedule_label.hpp
            include/schedule/schedule.hpp
            include/schedule/schedules.hpp
            include/table/column_id.hpp
            include/table/column_traits.hpp
            include/table/column.hpp
            include/table/table_id.hpp
            include/table/table_row.hpp
            include/table/table.hpp
            include/world/entity_meta.hpp
            include/world/world.hpp
)

target_link_libraries(carrots_ecs
    PUBLIC
        tracing
        carrots_std
)

set_target_properties(carrots_ecs PROPERTIES FOLDER "modules/carrots_ecs")


# Tests
add_executable(carrots_ecs_tests
    tests/archetype_tests.cpp
    tests/component_id_tests.cpp
    tests/column_tests.cpp
    tests/entity_tests.cpp
    tests/query_tests.cpp
    tests/schedule_tests.cpp
    tests/table_tests.cpp
    tests/world_tests.cpp
)

target_link_libraries(carrots_ecs_tests
    PRIVATE
        GTest::gtest_main
        carrots_ecs
)

include(GoogleTest)
gtest_discover_tests(carrots_ecs_tests)