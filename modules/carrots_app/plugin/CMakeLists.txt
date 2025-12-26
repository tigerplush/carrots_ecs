add_library(plugin INTERFACE
)

target_sources(plugin
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            include
        FILES
            include/plugin/Plugin.hpp
)

target_link_libraries(plugin
    PUBLIC
)

set_target_properties(plugin PROPERTIES FOLDER "modules/carrots_std/plugin")

# Tests
add_executable(plugin_tests
    tests/PluginTests.cpp
)

target_link_libraries(plugin_tests
    PRIVATE
        GTest::gtest_main
        plugin
)

include(GoogleTest)
gtest_discover_tests(plugin_tests)