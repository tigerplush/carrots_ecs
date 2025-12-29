#include <gtest/gtest.h>
#include <carrots_ecs.hpp>

using namespace carrots_ecs;

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