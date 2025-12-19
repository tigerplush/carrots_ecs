Hi, I'm Emily and I'm a bunny girl.
What drives bunnies? Well, carrots of course!
So I proudly present:

# Carrots ECS

An open source, ECS game engine written in c++.

## Project Guidelines
1. Everything should be in it's own module, when sensible. They can be grouped together in parent modules, but don't leak private modules.
2. Every module should feature a test, when possible

## Coding Guidelines

1. Use `snake_case` for methods and variables.
2. Use `CamelCase` for class and struct names.
3. Prefix private variables with `m_`. Prefix temporary variables with `t_`
4. Use wrapper structs to denote types that shouldn't be mixed, like `ColumnId` or `TableId`
5. Class definitions should start with the public methods, their API so to speak
6. Every public method has to be documented