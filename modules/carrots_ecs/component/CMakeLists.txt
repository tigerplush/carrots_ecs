add_library(component STATIC
    src/ComponentId.cpp
)

target_sources(component
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            include
        FILES
            include/component/ComponentId.hpp
)

set_target_properties(component PROPERTIES FOLDER "modules/carrots_ecs/component")

# Tests
add_executable(component_tests
    tests/ComponentIdTests.cpp
)

target_link_libraries(component_tests
    PRIVATE
        GTest::gtest_main
        component
)

include(GoogleTest)
gtest_discover_tests(component_tests)