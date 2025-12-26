add_library(schedule INTERFACE
)

target_sources(schedule
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            include
        FILES
            include/schedule/Schedule.hpp
            include/schedule/ScheduleLabel.hpp
)

target_link_libraries(schedule
    INTERFACE
)

set_target_properties(schedule PROPERTIES FOLDER "modules/carrots_std/schedule")

# Tests
add_executable(schedule_tests
    tests/ScheduleTests.cpp
)

target_link_libraries(schedule_tests
    PRIVATE
        GTest::gtest_main
        schedule
)

include(GoogleTest)
gtest_discover_tests(schedule_tests)