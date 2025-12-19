#include <gtest/gtest.h>

#include "archetype/Archetype.hpp"

using namespace CarrotsEcs::Archetype;

struct Position
{

};

struct Velocity
{

};

struct Name
{

};

TEST(ArchetypeTest, SimpleEq)
{
    Archetype lhs = Archetype::from<Position>();
    Archetype rhs = Archetype::from<Position>();
    EXPECT_EQ(lhs, rhs);
}

TEST(ArchetypeTest, SimpleNe)
{
    Archetype lhs = Archetype::from<Position>();
    Archetype rhs = Archetype::from<Velocity>();
    EXPECT_NE(lhs, rhs);
}

TEST(ArchetypeTest, ComplexEq)
{
    Archetype lhs = Archetype::from<Position, Velocity>();
    Archetype rhs = Archetype::from<Velocity, Position>();
    EXPECT_EQ(lhs, rhs);
}

TEST(ArchetypeTest, ComplexNe)
{
    Archetype lhs = Archetype::from<Position, Velocity>();
    Archetype rhs = Archetype::from<Velocity, Name>();
    EXPECT_NE(lhs, rhs);
}