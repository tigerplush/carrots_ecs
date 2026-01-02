#include <gtest/gtest.h>

#include <iostream>
#include <ostream>

#include <carrots_ecs.hpp>

using namespace carrots_ecs;

struct Position
{
    Position(int t_x, int t_y) : x(t_x), y(t_y){}
    int x;
    int y;

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

TEST(ColumnTest, DirectInsert)
{
    Column<Position> column;
    Position pos(5, 5);
    
    column.emplace_back(Position(5, 5));
    
    EXPECT_EQ(column.count(), 1);
    
    TableRow row(0);
    const void* ptr = column.at(row);
    const Position* retrieved = static_cast<const Position*>(ptr);
    
    std::cout << "Direct column test - Retrieved: " << *retrieved << std::endl;
    
    EXPECT_EQ(retrieved->x, 5);
    EXPECT_EQ(retrieved->y, 5);
}