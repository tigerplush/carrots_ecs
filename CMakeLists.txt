cmake_minimum_required(VERSION 3.23)

project(carrots LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_library(carrots INTERFACE
)

target_sources(carrots
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            src
        FILES
            src/Carrots.hpp
)

target_link_libraries(carrots
    INTERFACE
    carrots_internal
)

# Tests

enable_testing()

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
)

FetchContent_MakeAvailable(googletest)

add_subdirectory(examples)
add_subdirectory(modules)
add_subdirectory(tools)