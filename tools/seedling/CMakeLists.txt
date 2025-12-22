add_executable(seedling
    src/main.cpp
    src/Crate.cpp
)

target_link_libraries(seedling
    PRIVATE
    iterator
)

include(FetchContent)
FetchContent_Declare(
    cli11_proj
    QUIET
    GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git
    GIT_TAG v2.6.1
)

FetchContent_MakeAvailable(cli11_proj)

# And now you can use it
target_link_libraries(seedling PRIVATE CLI11::CLI11)