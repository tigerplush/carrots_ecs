add_executable(minimal
    src/HelloWorld.cpp
)

target_link_libraries(minimal
    PRIVATE
    carrots
)