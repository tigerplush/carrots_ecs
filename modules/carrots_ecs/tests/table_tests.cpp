#include <gtest/gtest.h>
#include <iostream>
#include <ostream>

#include <carrots_ecs.hpp>

using namespace carrots_ecs;

struct Position
{
    int x;
    int y;
    Position(int a=0,int b=0): x(a), y(b) { std::cout << "ctor\n"; }
    Position(const Position& o): x(o.x), y(o.y) { std::cout << "copy\n"; }
    Position(Position&& o): x(o.x), y(o.y) { std::cout << "move\n"; }
    Position& operator=(const Position& o) { x=o.x;y=o.y; std::cout << "copy=\n"; return *this;}
    bool operator==(const Position& other) const
    {
        return x == other.x && y == other.y;
    }

    friend std::ostream &operator<<(std::ostream &os, const Position &other)
    {
        os << "Position { " << other.x << ", " << other.y << " }";
        return os;
    }
};

template class carrots_ecs::table::Column<Position>;

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
    Position pos(5, 5);
    std::cout << "Original pos: " << pos << std::endl;
    TableRow row = table.insert(entity, Position {5, 5});
    EXPECT_EQ(table.component_count(), 1);
    EXPECT_EQ(table.entity_count(), 1);
    const void * ptr = table.get_component(ComponentId::from<Position>(), row);
    EXPECT_NE(ptr, nullptr);
    Position recasted_pos = *static_cast<const Position*>(ptr);
    std::cout << "Recasted pos: " << recasted_pos << std::endl;
    EXPECT_EQ(recasted_pos, pos);
}

TEST(TableTest, ContainsComponent)
{
    ComponentId position_component_id = ComponentId::from<Position>();
    ComponentId velocity_component_id = ComponentId::from<Velocity>();
    Table table = Table::from<Position>();
    EXPECT_TRUE(table.contains_component(position_component_id));
    EXPECT_FALSE(table.contains_component(velocity_component_id));
}