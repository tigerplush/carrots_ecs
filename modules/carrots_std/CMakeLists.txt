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
)

target_link_libraries(world
    INTERFACE
        iterator
        option
)