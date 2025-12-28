#include <gtest/gtest.h>
#include <carrots_std.hpp>

using namespace carrots_std;

TEST(OptionTest, OptionNone)
{
    Option<int> none = None;
    EXPECT_TRUE(none.is_none());
    EXPECT_FALSE(none.is_some());
}

TEST(OptionTest, OptionSome)
{
    Option<int> some = Some(5);
    EXPECT_TRUE(some.is_some());
    EXPECT_FALSE(some.is_none());
}

TEST(OptionTest, OptionCompare)
{
    Option<int> none = None;
    Option<int> some = Some(5);
    EXPECT_NE(some, none);
}

TEST(OptionTest, OptionUnwrap)
{
    EXPECT_EQ(Some(5).unwrap(), 5);
    EXPECT_NE(Some(5).unwrap(), 7);
    Option<int> panic = None;
    EXPECT_DEATH({panic.unwrap();}, "");
}

TEST(OptionTest, OptionRef)
{
    int number = 5;
    Option<int&> some = Some(number);
    EXPECT_EQ(some.unwrap(), 5);
}