add_library(archetype STATIC
    src/Archetype.cpp
)

target_sources(archetype
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            include
        FILES
            include/archetype/Archetype.hpp
            include/archetype/ArchetypeHasher.hpp
)

# Tests
add_executable(archetype_tests
    tests/ArchetypeTests.cpp
)

target_link_libraries(archetype_tests
    PRIVATE
        GTest::gtest_main
        archetype
)

include(GoogleTest)
gtest_discover_tests(archetype_tests)