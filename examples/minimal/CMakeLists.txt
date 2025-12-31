add_executable(minimal
    src/minimal.cpp
)

target_link_libraries(minimal
    PRIVATE
    carrots
)