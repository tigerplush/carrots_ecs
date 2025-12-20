#include <gtest/gtest.h>

#include "table/Table.hpp"

using namespace CarrotsEcs::Entity;
using namespace CarrotsEcs::Table;

struct Position
{
    int x;
    int y;

    bool operator==(const Position& other) const
    {
        return x == other.x && y == other.y;
    }
};

struct Velocity
{
};

TEST(TableTest, CreateTable)
{
    Table table = Table::from<Position>();
    EXPECT_EQ(table.component_count(), 1);
    table = Table::from<Position, Velocity>();
    EXPECT_EQ(table.component_count(), 2);
}

TEST(TableTest, InsertComponent)
{
    Entity entity(0);
    Table table = Table::from<Position>();
    Position pos{5, 5};
    table.insert(entity, Position {5, 5});
    EXPECT_EQ(table.component_count(), 1);
    EXPECT_EQ(table.entity_count(), 1);
    const void * ptr = table.get_component(ComponentId::from<Position>(), TableRow(0));
    EXPECT_NE(ptr, nullptr);
    EXPECT_EQ(pos, pos);
    EXPECT_EQ(*static_cast<const Position*>(ptr), pos);
}

TEST(TableTest, ContainsComponent)
{
    ComponentId position_component_id = ComponentId::from<Position>();
    ComponentId velocity_component_id = ComponentId::from<Velocity>();
    Table table = Table::from<Position>();
    EXPECT_TRUE(table.contains_component(position_component_id));
    EXPECT_FALSE(table.contains_component(velocity_component_id));
}