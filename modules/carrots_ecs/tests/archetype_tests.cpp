#include <gtest/gtest.h>
#include <carrots_ecs.hpp>

using namespace carrots_ecs;

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

TEST(ArchetypeTest, SimpleHashes)
{
    Archetype pos_1 = Archetype::from<Position>();
    Archetype pos_2 = Archetype::from<Position>();
    Archetype vel_1 = Archetype::from<Velocity>();
    Archetype vel_2 = Archetype::from<Velocity>();
    EXPECT_EQ(pos_1.hash_code(), pos_2.hash_code());
    EXPECT_EQ(vel_1.hash_code(), vel_2.hash_code());
    EXPECT_NE(pos_1.hash_code(), vel_1.hash_code());
}

TEST(ArchetypeTest, ComplexHashes)
{
    Archetype pos_vel_1 = Archetype::from<Position, Velocity>();
    Archetype pos_vel_2 = Archetype::from<Position, Velocity>();
    Archetype vel_name = Archetype::from<Velocity, Name>();
    EXPECT_EQ(pos_vel_1.hash_code(), pos_vel_2.hash_code());
    EXPECT_NE(pos_vel_1.hash_code(), vel_name.hash_code());
}