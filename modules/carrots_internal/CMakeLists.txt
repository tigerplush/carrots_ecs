add_library(carrots_internal INTERFACE
)

target_sources(carrots_internal
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            include
        FILES
            include/CarrotsInternal.hpp
            include/Prelude.hpp
)

target_link_libraries(carrots_internal
    INTERFACE
    carrots_app
)