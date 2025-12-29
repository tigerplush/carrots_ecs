#include <gtest/gtest.h>
#include <carrots_ecs.hpp>

using namespace carrots_ecs;

struct Position
{

};

struct Velocity
{

};

TEST(ComponentIdTest, SimpleEq)
{
    ComponentId lhs = ComponentId::from<Position>();
    ComponentId rhs = ComponentId::from<Position>();
    EXPECT_EQ(lhs, rhs);
}

TEST(ComponentIdTest, SimpleNe)
{
    ComponentId lhs = ComponentId::from<Position>();
    ComponentId rhs = ComponentId::from<Velocity>();
    EXPECT_NE(lhs, rhs);
}