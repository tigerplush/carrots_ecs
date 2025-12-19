#include <gtest/gtest.h>

#include "component/ComponentId.hpp"

using namespace CarrotsEcs::Component;

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