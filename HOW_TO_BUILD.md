# How to Build
1. Create project with `cmake -S . -B build`
2. Build everything with `cmake --build build`

# Test
1. Run tests with `ctest.exe --test-dir build`

# Project Guidelines
1. Everything should be in it's own module, when sensible. They can be grouped together in parent modules, but don't leak private modules.
2. Every module should feature a test, when possible