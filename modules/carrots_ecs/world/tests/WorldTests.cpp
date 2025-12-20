#include <gtest/gtest.h>

#include "world/World.hpp"

using namespace CarrotsEcs::World;

struct Position
{

};

struct Velocity
{

};

TEST(WorldTest, CreateWorld)
{
    World world;
    EXPECT_EQ(world.is_empty(), true);
}

TEST(WorldTest, InsertComponent)
{
    World world;
    EXPECT_EQ(world.is_empty(), true);
    world.spawn(Position {});
    EXPECT_EQ(world.is_empty(), false);
}