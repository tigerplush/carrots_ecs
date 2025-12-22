#include <gtest/gtest.h>

#include "iterator/StringIterator.hpp"

using namespace CarrotsStd::Iterator;
using namespace CarrotsStd::Option;

TEST(StringIteratorTests, CreateIterator)
{
    StringIterator iter("test");
    EXPECT_TRUE(iter.next() == Some(std::string("test")));
    EXPECT_EQ(iter.next(), None);
}
