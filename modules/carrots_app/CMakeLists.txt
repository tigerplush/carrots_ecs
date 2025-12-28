add_library(carrots_app STATIC
    src/app/app.cpp
    src/app/main_schedule_plugin.cpp
    src/app/sub_app.cpp
)

target_sources(carrots_app
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            include
        FILES
            include/carrots_app.hpp
            include/app/app_traits.hpp
            include/app/app.hpp
            include/app/main_schedule_order.hpp
            include/app/main_schedule_plugin.hpp
            include/app/main_schedule.hpp
            include/app/sub_app.hpp
            include/app/sub_apps.hpp
            include/plugin/plugin_traits.hpp
            include/plugin/plugin.hpp
)

target_link_libraries(carrots_app
    PUBLIC
        carrots_ecs
)

set_target_properties(carrots_app PROPERTIES FOLDER "modules/carrots_app")


# Tests
add_executable(app_tests
    tests/app_tests.cpp
    tests/plugin_tests.cpp
)

target_link_libraries(app_tests
    PRIVATE
        GTest::gtest_main
        carrots_app
)

include(GoogleTest)
gtest_discover_tests(app_tests)