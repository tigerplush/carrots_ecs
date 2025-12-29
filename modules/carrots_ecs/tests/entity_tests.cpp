#include <gtest/gtest.h>
#include <carrots_ecs.hpp>

using namespace carrots_ecs;

TEST(EntityTest, CreateEntity)
{
    Entity entity(0);
    EXPECT_NE(entity, Entity::PLACEHOLDER);
}