# Coding Guidelines

1. Use `snake_case` for methods and variables.
2. Use `CamelCase` for class and struct names.
3. Prefix private variables with `m_`. Prefix temporary variables with `t_`
4. Use wrapper structs to denote types that shouldn't be mixed, like `ColumnId` or `TableId`
5. Class definitions should have their types in the following order, each for public, protected and private:
    1. using statements
    2. static methods
    3. constructors
    4. Operator overloads
    5. Interface implementations
    6. API
    7. Members (avoid in public, if possible)

6. Every class and every public method has to be documented with three slashes `///`
7. Every header has to have an inclusion guard following the scheme `<PROJECT>_<MODULE>_<SUMODULE...>_FILENAME_HPP_`, such as `CARROTS_ECS_TABLE_TABLE_HPP_`
8. Every class has to be in a namespace of their parent module, which in turn is in the namespace of its parent module.
    1. namespaces are also `snake_case`
9. Every module should feature their "main" hpp to export all needed include