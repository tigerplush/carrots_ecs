add_executable(hello_world
    src/HelloWorld.cpp
)

target_link_libraries(hello_world
    PRIVATE
    carrots
)