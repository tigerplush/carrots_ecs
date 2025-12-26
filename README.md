Hi, I'm Emily and I'm a bunny girl.
What drives bunnies? Well, carrots of course!
So I proudly present:

# Carrots

An open source, ECS game engine written in c++.

## How to Build
1. Create project with `cmake -S . -B build`
2. Build everything with `cmake --build build`

## Test
1. Run tests with `ctest.exe --test-dir build`

## Project Guidelines
1. Everything should be in it's own module, when sensible. They can be grouped together in parent modules, but don't leak private modules.
2. Every module should feature a test, when possible

## Coding Guidelines

1. Use `snake_case` for methods and variables.
2. Use `CamelCase` for class and struct names.
3. Prefix private variables with `m_`. Prefix temporary variables with `t_`
4. Use wrapper structs to denote types that shouldn't be mixed, like `ColumnId` or `TableId`
5. Class definitions should have their types in the following order, each for public, protected and private:
    1. using statements
    2. static methods
    3. constructors
    4. Interface implementations
    5. API
    6. Members (avoid, if possible)

6. Every class and every public method has to be documented with three slashes `///`
7. Every header has to have an inclusion guard following the scheme `<PROJECT>_<MODULE>_<SUMODULE...>_FILENAME_HPP_`, such as `CARROTS_ECS_TABLE_TABLE_HPP_`
8. Every class has to be in a namespace of their parent module, which in turn is in the namespace of its parent module.
9. Every module should feature their "main" hpp to export all needed include