#include <gtest/gtest.h>

#include "world/World.hpp"

using namespace CarrotsEcs::World;

TEST(WorldTest, CreateWorld)
{
    World world;
    EXPECT_EQ(world.is_empty(), true);
}

TEST(WorldTest, InsertComponent)
{
}