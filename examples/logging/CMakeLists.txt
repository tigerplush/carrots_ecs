add_executable(logging
    src/Logging.cpp
)

target_link_libraries(logging
    PRIVATE
    carrots
)