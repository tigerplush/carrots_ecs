add_library(app STATIC
    src/App.cpp
)

target_sources(app
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            include
        FILES
            include/app/App.hpp
)

target_link_libraries(app
    PUBLIC
    carrots_std
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