add_subdirectory(log)

add_library(carrots_log INTERFACE)

target_sources(carrots_log
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            include
        FILES
            include/CarrotsLog.hpp
)

target_link_libraries(carrots_log
    INTERFACE
)

set_target_properties(carrots_log PROPERTIES FOLDER "modules/carrots_log")