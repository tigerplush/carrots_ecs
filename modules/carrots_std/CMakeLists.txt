add_subdirectory(iterator)
add_subdirectory(option)
add_subdirectory(result)

add_library(carrots_std INTERFACE)

target_sources(carrots_std
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            include
        FILES
            include/CarrotsStd.hpp
)

target_link_libraries(carrots_std
    INTERFACE
        iterator
        option
        result
)

set_target_properties(carrots_std PROPERTIES FOLDER "modules/carrots_std")