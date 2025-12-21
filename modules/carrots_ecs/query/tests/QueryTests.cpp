#include <gtest/gtest.h>

#include "world/World.hpp"
#include "query/Query.hpp"

using namespace CarrotsEcs::World;
using namespace CarrotsEcs::Query;

struct Position
{
};

struct Velocity
{
};

TEST(QueryTest, CreateQuery)
{
    World world;
    world.spawn(Position {});
    Query<Components<Position&>> query = Query<Components<Position&>>(world);
    EXPECT_EQ(query.matching_tables(), 1);
    EXPECT_EQ(query.iter().count(), 1);
    EXPECT_EQ(query.count(), 1);
    world.spawn(Position {}, Velocity {});
    Query<Components<Position&>> secondQuery = Query<Components<Position&>>(world);
    EXPECT_EQ(secondQuery.matching_tables(), 2);
    EXPECT_EQ(secondQuery.count(), 2);
}

TEST(QueryTest, IterQuery)
{
    World world;
    world.spawn(Position {});
    Query<Components<Entity, Position&>> query = Query<Components<Entity, Position&>>(world);
    for(auto [entity, pos]: query.iter())
    {
        EXPECT_EQ(entity.id(), 0);
    }
}

TEST(QueryTest, IterConstQuery)
{
    World world;
    world.spawn(Position {});
    Query<Components<Entity, const Position&>> query = Query<Components<Entity, const Position&>>(world);
    for(auto [entity, pos]: query.iter())
    {
        EXPECT_EQ(entity.id(), 0);
    }
}