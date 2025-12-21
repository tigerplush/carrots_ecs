#include <gtest/gtest.h>

#include "world/World.hpp"
#include "query/Query.hpp"

using namespace CarrotsEcs::World;
using namespace CarrotsEcs::Query;

struct Position
{
};

TEST(QueryTest, CreateQuery)
{
    World world;
    world.spawn(Position {});
    Query<Position&> query = Query<Position&>(world);
    EXPECT_EQ(query.iter().count(), 1);
    EXPECT_EQ(query.count(), 1);
}


TEST(QueryTest, IterQuery)
{
    World world;
    world.spawn(Position {});
    // Query<Entity, Position&> query = Query<Entity, Position&>(world);
    // for(auto i: query.iter())
    // {
        
    // }
}