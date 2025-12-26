add_subdirectory(archetype)
add_subdirectory(component)
add_subdirectory(entity)
add_subdirectory(query)
add_subdirectory(schedule)
add_subdirectory(table)
add_subdirectory(world)


add_library(carrots_ecs INTERFACE)

target_sources(carrots_ecs
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            include
        FILES
            include/CarrotsEcs.hpp
)

target_link_libraries(carrots_ecs
    INTERFACE
    archetype
    component
    entity
    query
    schedule
    table
    world
)

set_target_properties(carrots_ecs PROPERTIES FOLDER "modules/carrots_ecs")