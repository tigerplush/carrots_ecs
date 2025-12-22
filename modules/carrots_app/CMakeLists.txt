add_subdirectory(app)


add_library(carrots_app INTERFACE)

target_sources(carrots_app
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            include
        FILES
            include/CarrotsApp.hpp
)

target_link_libraries(carrots_app
    INTERFACE
    app
)

set_target_properties(carrots_app PROPERTIES FOLDER "modules/carrots_std")