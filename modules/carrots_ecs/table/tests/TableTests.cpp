#include <gtest/gtest.h>

#include "Table.hpp"

using namespace CarrotsEcs::Table;

struct Position
{
};

struct Velocity
{
};

TEST(TableTest, CreateTable)
{
    Table table = Table(Position {});
    EXPECT_EQ(table.number_of_components(), 1);
    table = Table(Position {}, Velocity {});
    EXPECT_EQ(table.number_of_components(), 2);
}