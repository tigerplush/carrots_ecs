#include <gtest/gtest.h>
#include "option/Option.hpp"

using namespace CarrotsStd::Option;

TEST(OptionTest, OptionNone)
{
    Option<int> lhs = None;
    Option<int> rhs = None;
    Option<int> some_rhs = Some(5);
    EXPECT_EQ(lhs, rhs);
    EXPECT_NE(lhs, Some(5));
    EXPECT_NE(None, Some(5));
}

TEST(OptionTest, OptionSome)
{
    EXPECT_EQ(Some(5), Some(5));
    EXPECT_NE(Some(5), Some(7));
}