#include <gtest/gtest.h>

#include "entity/Entity.hpp"

using namespace CarrotsEcs::Entity;

TEST(EntityTest, CreateEntity)
{
    Entity entity(0);
    EXPECT_NE(entity, Entity::PLACEHOLDER);
}