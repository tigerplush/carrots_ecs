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
    Query<Components<Position&>> query = Query<Components<Position&>>(world);
    EXPECT_EQ(query.matching_tables(), 1);
    EXPECT_EQ(query.iter().count(), 1);
    // EXPECT_EQ(query.count(), 1);
}


TEST(QueryTest, IterQuery)
{
    World world;
    world.spawn(Position {});
    Query<Components<Entity, Position&>> query = Query<Components<Entity, Position&>>(world);
    for(auto [entity, pos]: query.iter())
    {
        
    }
}