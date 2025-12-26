add_library(app STATIC
    src/App.cpp
    src/MainSchedulePlugin.cpp
    src/SubApp.cpp
)

target_compile_definitions(app PRIVATE TRACING_LOG_MODULE_NAME="carrots_app::app")

target_sources(app
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            include
        FILES
            include/app/App.hpp
            include/app/IApp.hpp
            include/app/MainSchedule.hpp
            include/app/SubApp.hpp
            include/app/SubApps.hpp
)

target_link_libraries(app
    PUBLIC
    tracing
    carrots_std
    carrots_ecs
    plugin
)

set_target_properties(app PROPERTIES FOLDER "modules/carrots_std/app")

# Tests
add_executable(app_tests
    tests/AppTests.cpp
)

target_link_libraries(app_tests
    PRIVATE
        GTest::gtest_main
        app
)

include(GoogleTest)
gtest_discover_tests(app_tests)